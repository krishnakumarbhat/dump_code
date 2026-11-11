/*===========================================================================*\
 * FILE: dd_mmic.c
 *===========================================================================
 * Copyright (C) 2026 Aptiv Advanced Safety and User Experience. All rights
 * reserved.
 * Confidential (C) Restricted Aptiv information. Do not disclose.
 *
 * DESCRIPTION:
 * This is the application/interface file that defines RFE (MMIC) configuration APIs
 *
 * ABBREVIATIONS:
 *   List of abbreviations used, or reference(s) to external document(s)
 *   RFE - Radar Front End
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *
 *   Requirements Document(s):
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN "Aptiv C Coding Standards" [30-Mar-2018]
 *
 * DEVIATIONS FROM STANDARDS:
 *   None.
 *
\*===========================================================================*/
/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/
#include <string.h>

/*===========================================================================*
 * Other Header Files
 *===========================================================================*/
#include "Fls.h"
#include "SWC_PLT_Service_IoHwAb.h"
#include "SchM_Fls.h"
#include "Uart.h"
#include "reuse.h"
// #include "crc32.h"
#include "dd_gpt.h"
#include "dd_mipi.h"
#include "dd_mmic.h"
#include "mars_api.h"
// #include "mars_l2_actions.h"
// #include "mars_l2_private.h"
#include "mipi_interrupt.h"
#include "mmic_error.h"
#include "mmic_interface.h"
#include "radar_data.h"
#include "sh_comm.h"
#include "sh_module_cfg.h"
#include "smc_cal.h"
#include "usc_cal.h"

// #ifdef CMSIS_ENVIRONMENT
#include "r52_l0_crc.h"
#include "r52_l0_gpio.h"
#include "r52_l0_oc.h"
#include "r52_l0_ssi.h"
#include "r52_l0_tmr.h"

#pragma clang section bss = ".tcma_mem_bss"

/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
#define MAX_MMIC_INIT_TRIALS                 (10U)
#define TABLE_0_ENTRIES_PER_LOOK             (512U)
#define TABLE_1_ENTRIES_PER_LOOK             (8U)
#define MMIC_SFT_ERR_SET                     (1U)
#define TEMP_RESOLUTION                      (0.1F)
#define MMIC_NON_RECOVERABLE_FAULT_THRESHOLD (3U)
#define MIPI_CSI2_DATA_ERR_THRESHOLD         (3U)
#define MMIC_FUSA_FAULT_HYSTERESIS_CYCLES    (3U)
#define MARS_OTP_VERSION_V10                 (10U)
#ifndef NUM_OF_LOOKS
   #define NUM_OF_LOOKS (9U)
#endif
#ifndef DDMA_CODES_LENGTH
   #define DDMA_CODES_LENGTH (4U)
#endif
#ifndef PHASE_TABLE_SIZE
   #define PHASE_TABLE_SIZE (512U)
#endif
#ifndef MAX_TABLE_1_SIZE
   #define MAX_TABLE_1_SIZE (8U)
#endif

/* Phase Rotator Calibration Macros */
#define PHASE_ROTATOR_PATTERN_CYCLE 512U
#define PHASE_ROTATOR_STEPS_PER_TX  64U

// TxPhase0 segment: indices 384-511
#define TXPHASE0_START (3 * PHASE_ROTATOR_STEPS_PER_TX)
#define TXPHASE0_END   (4 * PHASE_ROTATOR_STEPS_PER_TX - 1)

// TxPhase1 segment: indices 256-383
#define TXPHASE1_START (2 * PHASE_ROTATOR_STEPS_PER_TX)
#define TXPHASE1_END   (3 * PHASE_ROTATOR_STEPS_PER_TX - 1)

// TxPhase2 segment: indices 128-255
#define TXPHASE2_START (1 * PHASE_ROTATOR_STEPS_PER_TX)
#define TXPHASE2_END   (2 * PHASE_ROTATOR_STEPS_PER_TX - 1)

// TxPhase3 segment: indices 0-127
#define TXPHASE3_START 0U
#define TXPHASE3_END   (PHASE_ROTATOR_STEPS_PER_TX - 1)

/*Phase Rotator Calibration Configuration */
#define CALIB_FS_NUM_BLOCKS        4U
#define CALIB_FS_VALUE_1           8315405U /* Frequency sweep value for blocks LOOK_A, LOOK_C */
#define CALIB_FS_VALUE_2           8313961U /* Frequency sweep value for blocks LOOK_B, LOOK_D */
#define CALIB_TX_EN_TX3            8U       /* TX bit-mask for TX3 (binary 1000) */
#define CALIB_TX_EN_TX2            4U       /* TX bit-mask for TX2 (binary 0100) */
#define CALIB_TX_EN_TX1            2U       /* TX bit-mask for TX1 (binary 0010) */
#define CALIB_TX_EN_TX0            1U       /* TX bit-mask for TX0 (binary 0001) */
#define CALIB_RX_EN_ANT_AB_PATTERN 85U      /* RX antenna enable pattern (0x55 = 01010101) */
#define CALIB_TD_THRESHOLD_INDEX   4096U    /* Td timing decision threshold (indices >= 4096) */
#define CALIB_TD_DELAY_ACTIVE      60U      /* Td delay value when active (microseconds) */
#define CALIB_TD_DELAY_INACTIVE    0U       /* Td delay value when inactive */

/*retry count */
#define RETRY_COUNT (3U)

#if defined(MARS_HW_REV_A0)
   #define MAF_ARRAY_SIZE          (11346)
   #define MARS_INIT(x)            mars_init_debug(x)
   #define MARS_REG_WRITE()        Mars_Register_Write_Custom_Post_Activation()
   #define MARS_LOG_CRITICAL_REG() MARS_Log_Critical_Regs()
#elif defined(MARS_HW_REV_B0)
   #define MAF_ARRAY_SIZE          (22760)
   #define MARS_INIT(x)            mars_init(x)
   #define MARS_REG_WRITE()        API_Ret_Val
   #define MARS_LOG_CRITICAL_REG() API_Ret_Val
#else
   #error "No MARS hardware revision selected."
#endif
#define MAF_DATA_SIZE (MAF_ARRAY_SIZE * 4) /* This will be dynamic but for now MAF_ARRAY_SIZE * sizeof(uint32_t) */
#define CHUNK_SIZE    1024                 /* 1KB chunk size (1024 bytes) */

#define MARS_PHY_FREQ_OFFSET_HZ 57600000000ULL
#define MARS_PHY_FREQ_SCALE_HZ  2400000000ULL

#define API_ONLY_ERROR_MASK 0x000FFFFF
#define SFT_ONLY_ERROR_MASK 0xFFF00000
#define LUT_ARRAY_SIZE      512U
#define MARS_NUM_TX_PORTS   4U
#define FUNC_LABEL_SIZE     (64U)

#if DEVELOP_UART
   /* Send UART message */
   #define UART_SEND_WRAP Uart_SendData
#else
   /* do nothing */
   #define UART_SEND_WRAP Uart_SendData_Dummy
static void Uart_SendData_Dummy(const void *const data, uint32_t len, Uart_ChannelType channel);
#endif

/* Convert raw value to temperature in degrees Celsius */
#define MARS_RAW_TO_TEMP_DEGC(raw_value) (((float32_t)(raw_value) / 16.0F) - 50.0F)

/* PVT polynomial (Exec Spec): T = c4*x^4 + c3*x^3 + c2*x^2 + c1*x + c0 */
#define MARS_PVT_AVG_VALUE_MASK (0x0FFFU)
#define MARS_PVT_TEMP_COEFF_X4  (-1.08168e-13)
#define MARS_PVT_TEMP_COEFF_X3  (1.73665e-9)
#define MARS_PVT_TEMP_COEFF_X2  (-1.48650e-5)
#define MARS_PVT_TEMP_COEFF_X1  (9.32829e-2)
#define MARS_PVT_TEMP_COEFF_X0  (-5.45788e+1)
#define MARS_PVT_POLYNOMIAL_TEMP_DEGC(x)                                                                                          \
   (((MARS_PVT_TEMP_COEFF_X4 * (x) + MARS_PVT_TEMP_COEFF_X3) * (x) + MARS_PVT_TEMP_COEFF_X2) * (x) * (x) +                        \
    MARS_PVT_TEMP_COEFF_X1 * (x) + MARS_PVT_TEMP_COEFF_X0)

/* Macros to split 64-bit values into 32-bit lower and upper parts for 4-byte alignment */
#define UINT64_TO_LOWER32(val) ((uint32_t)((val)&0xFFFFFFFFU))
#define UINT64_TO_UPPER32(val) ((uint32_t)(((val) >> 32) & 0xFFFFFFFFU))

/* Macros to extract individual bytes from a 32-bit value */
#define UINT32_BYTE3(val) ((uint8_t)(((val) >> 24) & 0xFFU)) /* Most significant byte */
#define UINT32_BYTE2(val) ((uint8_t)(((val) >> 16) & 0xFFU))
#define UINT32_BYTE1(val) ((uint8_t)(((val) >> 8) & 0xFFU))
#define UINT32_BYTE0(val) ((uint8_t)((val)&0xFFU)) /* Least significant byte */

#define MARS_READ_WAIT_CYCLES 1000U

/* Convert temperature in degrees Celsius to raw value */
#define MARS_TEMP_DEGC_TO_RAW(temp_degc) ((uint16)(((temp_degc) + 50.0F) * 16.0F))
#define MMIC_BIT_SET(v, b)               ((((v) >> (b)) & 0x1U) != 0U)
#define DOUBLE_BIT_CHECK(v, b, r)        ((((v) >> (b)) & 0x3U) == (r)) // v- value, b- shifting value, r- expected 2-bit result
#define MULTIPLE_BIT_CHECK(v, b, n, r)   Multiple_Bit_Check((v), (b), (n), (r))
#define BIT_SET                          0x01
#ifdef MARS_HW_REV_A0
   /* =================================================================== */
   /* A0-SPECIFIC REGISTERS - 4 registers                                 */
   /* These will be populated as 0 in the superset when building for B0   */
   /* =================================================================== */
   #define MARS_HW_REV_SPECIFIC(DCS_X) /* RX IFVGA_BIAS_TRIM Registers (4 registers - A0 ONLY) */                                 \
      DCS_X(MARS_F_CORE_BANK_RX0_IFVGA_BIAS_TRIM, Mars_F_Core_Bank_Rx0_Ifvga_Bias_Trim)                                           \
      DCS_X(MARS_F_CORE_BANK_RX1_IFVGA_BIAS_TRIM, Mars_F_Core_Bank_Rx1_Ifvga_Bias_Trim)                                           \
      DCS_X(MARS_F_CORE_BANK_RX2_IFVGA_BIAS_TRIM, Mars_F_Core_Bank_Rx2_Ifvga_Bias_Trim)                                           \
      DCS_X(MARS_F_CORE_BANK_RX3_IFVGA_BIAS_TRIM, Mars_F_Core_Bank_Rx3_Ifvga_Bias_Trim)
#endif

#ifdef MARS_HW_REV_B0
   /* =================================================================== */
   /* B0-SPECIFIC REGISTERS - 28 registers                                */
   /* These will be populated as 0 in the superset when building for A0   */
   /* =================================================================== */
   #define MARS_HW_REV_SPECIFIC(DCS_X)                                                                                            \
      /* TX0-3 PR_ITB_CG and VGA_VG2ST1/VG3ST1 (12 registers - B0 ONLY) */                                                        \
      DCS_X(MARS_F_CORE_BANK_TX0_PR_ITB_CG, Mars_F_Core_Bank_Tx0_Pr_Itb_Cg)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX0_VGA_VG2ST1, Mars_F_Core_Bank_Tx0_Vga_Vg2St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX0_VGA_VG3ST1, Mars_F_Core_Bank_Tx0_Vga_Vg3St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX1_PR_ITB_CG, Mars_F_Core_Bank_Tx1_Pr_Itb_Cg)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX1_VGA_VG2ST1, Mars_F_Core_Bank_Tx1_Vga_Vg2St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX1_VGA_VG3ST1, Mars_F_Core_Bank_Tx1_Vga_Vg3St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX2_PR_ITB_CG, Mars_F_Core_Bank_Tx2_Pr_Itb_Cg)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX2_VGA_VG2ST1, Mars_F_Core_Bank_Tx2_Vga_Vg2St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX2_VGA_VG3ST1, Mars_F_Core_Bank_Tx2_Vga_Vg3St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX3_PR_ITB_CG, Mars_F_Core_Bank_Tx3_Pr_Itb_Cg)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX3_VGA_VG2ST1, Mars_F_Core_Bank_Tx3_Vga_Vg2St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX3_VGA_VG3ST1, Mars_F_Core_Bank_Tx3_Vga_Vg3St1)                                                     \
      /* TX VGA VBB Registers (9 registers - B0 ONLY) */                                                                          \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VBB1ST1, Mars_F_Core_Bank_Tx_Vga_Vbb1St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VBB1ST2, Mars_F_Core_Bank_Tx_Vga_Vbb1St2)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VBB1ST3, Mars_F_Core_Bank_Tx_Vga_Vbb1St3)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VBB2ST1, Mars_F_Core_Bank_Tx_Vga_Vbb2St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VBB2ST2, Mars_F_Core_Bank_Tx_Vga_Vbb2St2)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VBB2ST3, Mars_F_Core_Bank_Tx_Vga_Vbb2St3)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VBB3ST1, Mars_F_Core_Bank_Tx_Vga_Vbb3St1)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VBB3ST2, Mars_F_Core_Bank_Tx_Vga_Vbb3St2)                                                     \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VBB3ST3, Mars_F_Core_Bank_Tx_Vga_Vbb3St3)                                                     \
      /* TX VGA VG Registers (7 registers - B0 ONLY) */                                                                           \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VG1ST1, Mars_F_Core_Bank_Tx_Vga_Vg1St1)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VG1ST2, Mars_F_Core_Bank_Tx_Vga_Vg1St2)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VG1ST3, Mars_F_Core_Bank_Tx_Vga_Vg1St3)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VG2ST2, Mars_F_Core_Bank_Tx_Vga_Vg2St2)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VG2ST3, Mars_F_Core_Bank_Tx_Vga_Vg2St3)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VG3ST2, Mars_F_Core_Bank_Tx_Vga_Vg3St2)                                                       \
      DCS_X(MARS_F_CORE_BANK_TX_VGA_VG3ST3, Mars_F_Core_Bank_Tx_Vga_Vg3St3)
#endif

#define MARS_LOG_CAL_REG_LIST(DCS_X)                                                                                              \
   /* =================================================================== */                                                      \
   /* COMMON REGISTERS (Both A0 and B0) - 49 registers                    */                                                      \
   /* =================================================================== */                                                      \
   /* LODST Registers (15 registers - COMMON) */                                                                                  \
   DCS_X(MARS_F_CORE_BANK_LODST_ASRX_CAP, Mars_F_Core_Bank_Lodst_Asrx_Cap)                                                        \
   DCS_X(MARS_F_CORE_BANK_LODST_ASRX_GAIN, Mars_F_Core_Bank_Lodst_Asrx_Gain)                                                      \
   DCS_X(MARS_F_CORE_BANK_LODST_ASTXRX_CAP, Mars_F_Core_Bank_Lodst_Astxrx_Cap)                                                    \
   DCS_X(MARS_F_CORE_BANK_LODST_ASTXRX_GAIN, Mars_F_Core_Bank_Lodst_Astxrx_Gain)                                                  \
   DCS_X(MARS_F_CORE_BANK_LODST_ASTX_CAP, Mars_F_Core_Bank_Lodst_Astx_Cap)                                                        \
   DCS_X(MARS_F_CORE_BANK_LODST_ASTX_GAIN, Mars_F_Core_Bank_Lodst_Astx_Gain)                                                      \
   DCS_X(MARS_F_CORE_BANK_LODST_QUAD_BIAS_AMP_CG, Mars_F_Core_Bank_Lodst_Quad_Bias_Amp_Cg)                                        \
   DCS_X(MARS_F_CORE_BANK_LODST_QUAD_BIAS_AMP_CS, Mars_F_Core_Bank_Lodst_Quad_Bias_Amp_Cs)                                        \
   DCS_X(MARS_F_CORE_BANK_LODST_QUAD_BIAS_DRV_CUR, Mars_F_Core_Bank_Lodst_Quad_Bias_Drv_Cur)                                      \
   DCS_X(MARS_F_CORE_BANK_LODST_QUAD_BIAS_FD1_CS, Mars_F_Core_Bank_Lodst_Quad_Bias_Fd1_Cs)                                        \
   DCS_X(MARS_F_CORE_BANK_LODST_QUAD_BIAS_FD2_CS, Mars_F_Core_Bank_Lodst_Quad_Bias_Fd2_Cs)                                        \
   DCS_X(MARS_F_CORE_BANK_LODST_QUAD_DRV_BGBN, Mars_F_Core_Bank_Lodst_Quad_Drv_Bgbn)                                              \
   DCS_X(MARS_F_CORE_BANK_LODST_QUAD_DRV_BGBP, Mars_F_Core_Bank_Lodst_Quad_Drv_Bgbp)                                              \
   DCS_X(MARS_F_CORE_BANK_LODST_RX_AS_ATT, Mars_F_Core_Bank_Lodst_Rx_As_Att)                                                      \
   DCS_X(MARS_F_CORE_BANK_LODST_TX_AS_ATT, Mars_F_Core_Bank_Lodst_Tx_As_Att)                                                      \
   /* RX0 Registers (5 registers - COMMON) */                                                                                     \
   DCS_X(MARS_F_CORE_BANK_RX0_IFVGA_FCTRIM_IN1, Mars_F_Core_Bank_Rx0_Ifvga_Fctrim_In1)                                            \
   DCS_X(MARS_F_CORE_BANK_RX0_IFVGA_FCTRIM_IN2, Mars_F_Core_Bank_Rx0_Ifvga_Fctrim_In2)                                            \
   DCS_X(MARS_F_CORE_BANK_RX0_IFVGA_OFFTRIM_STG2, Mars_F_Core_Bank_Rx0_Ifvga_Offtrim_Stg2)                                        \
   DCS_X(MARS_F_CORE_BANK_RX0_RFFE_LNA_BIAS, Mars_F_Core_Bank_Rx0_Rffe_Lna_Bias)                                                  \
   DCS_X(MARS_F_CORE_BANK_RX0_RFFE_MIXER_BIAS, Mars_F_Core_Bank_Rx0_Rffe_Mixer_Bias)                                              \
   /* RX1 Registers (5 registers - COMMON) */                                                                                     \
   DCS_X(MARS_F_CORE_BANK_RX1_IFVGA_FCTRIM_IN1, Mars_F_Core_Bank_Rx1_Ifvga_Fctrim_In1)                                            \
   DCS_X(MARS_F_CORE_BANK_RX1_IFVGA_FCTRIM_IN2, Mars_F_Core_Bank_Rx1_Ifvga_Fctrim_In2)                                            \
   DCS_X(MARS_F_CORE_BANK_RX1_IFVGA_OFFTRIM_STG2, Mars_F_Core_Bank_Rx1_Ifvga_Offtrim_Stg2)                                        \
   DCS_X(MARS_F_CORE_BANK_RX1_RFFE_LNA_BIAS, Mars_F_Core_Bank_Rx1_Rffe_Lna_Bias)                                                  \
   DCS_X(MARS_F_CORE_BANK_RX1_RFFE_MIXER_BIAS, Mars_F_Core_Bank_Rx1_Rffe_Mixer_Bias)                                              \
   /* RX2 Registers (5 registers - COMMON) */                                                                                     \
   DCS_X(MARS_F_CORE_BANK_RX2_IFVGA_FCTRIM_IN1, Mars_F_Core_Bank_Rx2_Ifvga_Fctrim_In1)                                            \
   DCS_X(MARS_F_CORE_BANK_RX2_IFVGA_FCTRIM_IN2, Mars_F_Core_Bank_Rx2_Ifvga_Fctrim_In2)                                            \
   DCS_X(MARS_F_CORE_BANK_RX2_IFVGA_OFFTRIM_STG2, Mars_F_Core_Bank_Rx2_Ifvga_Offtrim_Stg2)                                        \
   DCS_X(MARS_F_CORE_BANK_RX2_RFFE_LNA_BIAS, Mars_F_Core_Bank_Rx2_Rffe_Lna_Bias)                                                  \
   DCS_X(MARS_F_CORE_BANK_RX2_RFFE_MIXER_BIAS, Mars_F_Core_Bank_Rx2_Rffe_Mixer_Bias)                                              \
   /* RX3 Registers (5 registers - COMMON) */                                                                                     \
   DCS_X(MARS_F_CORE_BANK_RX3_IFVGA_FCTRIM_IN1, Mars_F_Core_Bank_Rx3_Ifvga_Fctrim_In1)                                            \
   DCS_X(MARS_F_CORE_BANK_RX3_IFVGA_FCTRIM_IN2, Mars_F_Core_Bank_Rx3_Ifvga_Fctrim_In2)                                            \
   DCS_X(MARS_F_CORE_BANK_RX3_IFVGA_OFFTRIM_STG2, Mars_F_Core_Bank_Rx3_Ifvga_Offtrim_Stg2)                                        \
   DCS_X(MARS_F_CORE_BANK_RX3_RFFE_LNA_BIAS, Mars_F_Core_Bank_Rx3_Rffe_Lna_Bias)                                                  \
   DCS_X(MARS_F_CORE_BANK_RX3_RFFE_MIXER_BIAS, Mars_F_Core_Bank_Rx3_Rffe_Mixer_Bias)                                              \
   /* RX Common Control Registers (5 registers - COMMON) */                                                                       \
   DCS_X(MARS_F_CORE_BANK_RX_BG_TRIM, Mars_F_Core_Bank_Rx_Bg_Trim)                                                                \
   DCS_X(MARS_F_CORE_BANK_RX_PISSA_GCTRL, Mars_F_Core_Bank_Rx_Pissa_Gctrl)                                                        \
   DCS_X(MARS_F_CORE_BANK_RX_PISSA_LDOCTRL, Mars_F_Core_Bank_Rx_Pissa_Ldoctrl)                                                    \
   DCS_X(MARS_F_CORE_BANK_RX_PISSA_VCOFFCTRL, Mars_F_Core_Bank_Rx_Pissa_Vcoffctrl)                                                \
   DCS_X(MARS_F_CORE_BANK_RX_PISSA_VDCTRL, Mars_F_Core_Bank_Rx_Pissa_Vdctrl)                                                      \
   /* TX PA Common Registers (9 registers - COMMON) */                                                                            \
   DCS_X(MARS_F_CORE_BANK_TX_PA_VB1_ST1, Mars_F_Core_Bank_Tx_Pa_Vb1_St1)                                                          \
   DCS_X(MARS_F_CORE_BANK_TX_PA_VB1_ST2, Mars_F_Core_Bank_Tx_Pa_Vb1_St2)                                                          \
   DCS_X(MARS_F_CORE_BANK_TX_PA_VG1_ST1_A, Mars_F_Core_Bank_Tx_Pa_Vg1_St1_A)                                                      \
   DCS_X(MARS_F_CORE_BANK_TX_PA_VG1_ST1_PTAT, Mars_F_Core_Bank_Tx_Pa_Vg1_St1_Ptat)                                                \
   DCS_X(MARS_F_CORE_BANK_TX_PA_VG2_ST1_A, Mars_F_Core_Bank_Tx_Pa_Vg2_St1_A)                                                      \
   DCS_X(MARS_F_CORE_BANK_TX_PA_VG2_ST1_PTAT, Mars_F_Core_Bank_Tx_Pa_Vg2_St1_Ptat)                                                \
   DCS_X(MARS_F_CORE_BANK_TX_PA_VG2_ST2_PTAT, Mars_F_Core_Bank_Tx_Pa_Vg2_St2_Ptat)                                                \
   DCS_X(MARS_F_CORE_BANK_TX_PA_VG3_ST2, Mars_F_Core_Bank_Tx_Pa_Vg3_St2)                                                          \
   DCS_X(MARS_F_CORE_BANK_TX_PR_CS_TB, Mars_F_Core_Bank_Tx_Pr_Cs_Tb)                                                              \
   MARS_HW_REV_SPECIFIC(DCS_X)

#define MARS_LOG_CAL_REG_NAME(x, y) x,
#define MARS_LOG_CAL_REG_ENUM(x, y) MARS_LOG_REG_##x,
#define MARS_LOG_CAL_REG_ADDR(x, y) &(MMIC_Stream.MMIC_Data.Mars_Calibration_Registers.y),

#define MMARS_CAL_LOG_REG_MAX (uint8_t) MARS_LOG_REG_MAX

#define MARS_LOG_CRITICAL_REG_LIST(DCS_X)                                                                                         \
   DCS_X(MARS_F_CPLL_BANK_LOCK, Mars_F_Cpll_Bank_Lock)                                                                            \
   DCS_X(MARS_F_CPLL_BANK_LOCK_REPLICA, Mars_F_Cpll_Bank_Lock_Replica)                                                            \
   /* DCS_X(MARS_R_CPLL_BANK_DBG_DIVCTR_SAMPLE_LSB, Mars_R_Cpll_Bank_Dbg_Divctr_Sample_Lsb) */                                    \
   /* DCS_X(MARS_F_CPLL_BANK_DIVCTR_SAMPLE_LSB, Mars_F_Cpll_Bank_Divctr_Sample_Lsb) */                                            \
   /* DCS_X(MARS_R_CPLL_BANK_DBG_DIGTUNE_LSB, Mars_R_Cpll_Bank_Dbg_Digtune_Lsb) */                                                \
   /* DCS_X(MARS_F_CPLL_BANK_DIGTUNE_LSB, Mars_F_Cpll_Bank_Digtune_Lsb) */                                                        \
   /* DCS_X(MARS_R_CPLL_BANK_DBG_DIGTUNE_MSB, Mars_R_Cpll_Bank_Dbg_Digtune_Msb) */                                                \
   /* DCS_X(MARS_F_CPLL_BANK_DIGTUNE_MSB, Mars_F_Cpll_Bank_Digtune_Msb) */                                                        \
   DCS_X(MARS_R_CPLL_BANK_REG_DBG_SW, Mars_R_Cpll_Bank_Reg_Dbg_Sw)                                                                \
   DCS_X(MARS_F_CPLL_BANK_SW_LOOPFILTEROVERRIDE, Mars_F_Cpll_Bank_Sw_Loopfilteroverride)                                          \
   DCS_X(MARS_R_CPLL_BANK_FSM_OVERRIDE, Mars_R_Cpll_Bank_Fsm_Override)                                                            \
   DCS_X(MARS_F_CPLL_BANK_FSM_OVERRIDE, Mars_F_Cpll_Bank_Fsm_Override)                                                            \
   DCS_X(MARS_R_CPLL_BANK_SW_LOOPFILTERVALUE_LSB, Mars_R_Cpll_Bank_Sw_Loopfiltervalue_Lsb)                                        \
   DCS_X(MARS_F_CPLL_BANK_SW_LOOPFILTERVALUE_LSB, Mars_F_Cpll_Bank_Sw_Loopfiltervalue_Lsb)                                        \
   DCS_X(MARS_R_CPLL_BANK_SW_LOOPFILTERVALUE_MSB, Mars_R_Cpll_Bank_Sw_Loopfiltervalue_Msb)                                        \
   DCS_X(MARS_F_CPLL_BANK_SW_LOOPFILTERVALUE_MSB, Mars_F_Cpll_Bank_Sw_Loopfiltervalue_Msb)                                        \
   DCS_X(MARS_R_CPLL_BANK_REG_TRIM_DCO, Mars_R_Cpll_Bank_Reg_Trim_Dco)                                                            \
   DCS_X(MARS_F_CPLL_BANK_CTRL_REG_DCO, Mars_F_Cpll_Bank_Ctrl_Reg_Dco)                                                            \
   DCS_X(MARS_R_CPLL_BANK_REG_LDO_TRIM, Mars_R_Cpll_Bank_Reg_Ldo_Trim)                                                            \
   DCS_X(MARS_F_CPLL_BANK_CTRL_REG_0P8, Mars_F_Cpll_Bank_Ctrl_Reg_0p8)                                                            \
   DCS_X(MARS_R_RXADC_FUSAIRQV, Mars_R_Rxadc_Fusairqv)                                                                            \
   DCS_X(MARS_R_CPU_SYS_MCU_ERR_0, Mars_R_Cpu_Sys_Mcu_Err_0)                                                                      \
   DCS_X(MARS_R_CPU_SYS_MCU_ERR_1, Mars_R_Cpu_Sys_Mcu_Err_1)                                                                      \
   DCS_X(MARS_R_CPU_SYS_MCU_ERR_2, Mars_R_Cpu_Sys_Mcu_Err_2)

#define MARS_LOG_CRITICAL_REG_NAME(x, y) x,
#define MARS_LOG_CRITICAL_REG_ADDR(x, y) &(MMIC_Stream.MMIC_Data.Mars_Critical_Registers.y),
#define MARS_LOG_CRITICAL_REG_ENUM(x, y) MARS_LOG_CRITICAL_REG_##x,
#define MARS_CRITICAL_REG_MAX            (uint8_t) MARS_LOG_CRITICAL_REG_MAX

#define MARS_BIAS_CFG_REG_LIST(DCS_X)                                                                                             \
   DCS_X(MARS_F_CORE_BANK_TX_BIAS_FILTER_CHR_ACT_CTRL, tx_bias_filter_chr_act_ctrl, 0x0U)                                         \
   DCS_X(MARS_F_CORE_BANK_TX_BIAS_FILTER_MOD_CTRL, tx_bias_filter_mod_ctrl, 0x01U)                                                \
   DCS_X(MARS_F_CORE_BANK_LODST_ASTXRX_BIAS_FILTER_CTRL, lodst_astxrx_bias_filter_ctrl, 0x01U)                                    \
   DCS_X(MARS_F_CORE_BANK_LODST_ASRX_BIAS_FILTER_CTRL, lodst_asrx_bias_filter_ctrl, 0x01U)                                        \
   DCS_X(MARS_F_CORE_BANK_LODST_ASTX_BIAS_FILTER_CTRL, lodst_astx_bias_filter_ctrl, 0x01U)                                        \
   DCS_X(MARS_F_CORE_BANK_TX_VGA_BIAS_FILTER_EN, tx_vga_bias_filter_en, 0x01U)                                                    \
   DCS_X(MARS_F_CORE_BANK_TX_VGA_BIAS_FILTER_SPEEDUP_DIS, tx_vga_bias_filter_speedup_dis, 0x0U)                                   \
   DCS_X(MARS_F_CORE_BANK_TX_PR_BIAS_FILTER_EN, tx_pr_bias_filter_en, 0x01U)                                                      \
   DCS_X(MARS_F_CORE_BANK_TX_PR_BIAS_FILTER_SPEEDUP_DIS, tx_pr_bias_filter_speedup_dis, 0x00U)                                    \
   DCS_X(MARS_F_CORE_BANK_TX_PA_BIAS_FILTER_DIS, tx_pa_bias_filter_dis, 0x00U)                                                    \
   DCS_X(MARS_F_CORE_BANK_TX_BIAS_FILTER_CHR_ACT_CTRL_POST_TX, tx_bias_filter_chr_act_ctrl_post_tx, 0x0U)                         \
   DCS_X(MARS_F_CORE_BANK_RX_PISSA_CBCTRL, rx_pissa_cbctrl, 0x00U)                                                                \
   DCS_X(MARS_F_CORE_BANK_LODST_TX_AS_ATT, lodst_tx_as_att, 0x00U)                                                                \
   DCS_X(MARS_F_CORE_BANK_LODST_ASTX_GAIN, lodst_astx_gain, 0x01U)

#define MARS_F_CORE_BANK_TX_BIAS_FILTER_CHR_ACT_CTRL_POST_TX MARS_F_CORE_BANK_TX_BIAS_FILTER_CHR_ACT_CTRL
#define MARS_BIAS_CFG_REG_VAL(x, y, z)                       (z),
#define MARS_BIAS_CFG_REG_NAME(x, y, z)                      x,
#define MARS_BIAS_CFG_REG_ENUM(x, y, z)                      MARS_BIAS_CFG_REG_##x,
#define MARS_BIAS_CFG_REG_FAIL(x, y, z)                      &(MARS_Bias_Write_Fail_Count.y),

#define MMARS_BIAS_CFG_REG_MAX (uint8_t) MARS_BIAS_CFG_REG_MAX

/*Operation Modes */
#define MMIC_APTIV_OP_MODE_NORMAL       ((uint8_t)0)
#define MMIC_APTIV_OP_MODE_CW           ((uint8_t)1)
#define MMIC_APTIV_OP_MODE_ACQ_CW       ((uint8_t)2)
#define MMIC_APTIV_OP_MODE_TEST_PATTERN ((uint8_t)3)
#define MAX_TIME_OUT_COUNT              (100U)

#define MAX_TIME_OUT_COUNT         (100U)
#define NUMBER_OF_TEMP_SENSORS     (8U)
#define TEMP_SENSOR_ENABLE_BITMASK 0x01U
/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/
/*XCP variable which is updated with appropriate value(from enum) to inject the respective fault*/
volatile XCP_MMIC_FIT_Enable_T XCP_MMIC_FIT_Enable = XCP_MMIC_NO_FIT_TEST;
MMIC_Stream_T MMIC_Stream                          = {0};
Debug_Stream_T Debug_Stream                        = {0};
MMIC_Temp_Stats_T MMIC_Temperature;
mars_uid_t Mars_UID = {0};
extern uint32_t __MARS_FW_FLASH_START_ADDRESS[];
uint32_t Measurement_debug_timer_ms                          = 0U;
bool MMIC_Frame_Force_Reconfig_MMIC                          = false;
Mars_Rfe_Mon_Status_T Mars_RFE_Mon                           = {0};
volatile uint8_t MMIC_API_Failure_Status[MAX_API_FAULT_TYPE] = {CODED_FALSE, CODED_FALSE, CODED_FALSE};
bool Is_Triggered_Once                                       = false;
/* Tracks up to 88 registers (81 needed for superset) */
uint8_t Failed_Reg_Mask[MARS_CALIBRATION_REGISTERS_FAILURE_ARRAY_SIZE] = {0};
mars_zhv_t ZHB_Data_From_MARS;
volatile bool MMIC_Phase_Rotator_Calib_Mode = false;
volatile uint8_t MMIC_High_Temp_Fault       = CODED_FALSE;
volatile uint8_t MMIC_Low_Temp_Fault        = CODED_FALSE;
uint8_t Mars_OTP_Version                    = 0;

typedef enum MMIC_RFE_Init_State_Tag
{
   MMIC_RFE_INIT_UPLOAD_ONLY = 0,
   MMIC_RFE_INIT_ACTIVATE_ONLY,
   MMIC_RFE_INIT_UPLOAD_THEN_ACTIVATE,
   MMIC_RFE_INIT_UPLOAD_ONLY_WITH_RESET_RETRY
} MMIC_RFE_Init_State_T;

MMIC_RFE_Init_State_T MMIC_RFE_Init_State = MMIC_RFE_INIT_UPLOAD_ONLY;
/*===========================================================================*
 * Exported type declarations (enum, struct, union, typedef)
 *===========================================================================*/
typedef enum Mars_Bias_Cfg_Tag
{
   MARS_BIAS_CFG_REG_LIST(MARS_BIAS_CFG_REG_ENUM) MARS_BIAS_CFG_REG_MAX
} Mars_Bias_Cfg_T;

typedef enum Mars_Log_Cal_Tag
{
   MARS_LOG_CAL_REG_LIST(MARS_LOG_CAL_REG_ENUM) MARS_LOG_REG_MAX
} Mars_Log_Cal_T;

typedef enum Mars_Log_Critical_Tag
{
   MARS_LOG_CRITICAL_REG_LIST(MARS_LOG_CRITICAL_REG_ENUM) MARS_LOG_CRITICAL_REG_MAX
} Mars_Log_Critical_T;

typedef enum MMIC_RW_Custom_Tag
{
   MMIC_RW_CUSTOM_ACCESS_READ    = 0,
   MMIC_RW_CUSTOM_ACCESS_WRITE   = 1,
   MMIC_RW_CUSTOM_ACCESS_INVALID = 0xF
} MMIC_RW_Custom_T;

typedef struct MMIC_Reg_RW_Custom_Tag
{
   MMIC_RW_Custom_T access_type;
   uint32_t reg_address;
   uint32_t reg_value;
   Mars_ReturnType return_status;
} MMIC_Reg_RW_Custom_T;

typedef struct MMIC_Memblk_RW_Custom_Tag
{
   MMIC_RW_Custom_T access_type;
   uint32_t memblk_address;
   uint32_t memblk_value;
   Mars_ReturnType return_status;
} MMIC_Memblk_RW_Custom_T;

typedef struct MARS_SFT_Error_Counter_Tag
{
   // uint8_t mars_init_debug_sft_error;
   // uint8_t mars_qspi_sft_error;
   // uint8_t mars_upload_firmware_error;
   // uint8_t mars_write_register_sft_error;
   // uint8_t mars_activate_firmware_sft_error;
   // uint8_t mars_read_id_sft_error;
   // uint8_t mars_get_api_version_sft_error;
   // uint8_t mars_start_cw_sft_error;
   // uint8_t mars_stop_cw_sft_error;
   // uint8_t mars_enable_testpattern_sft_error;
   // uint8_t mars_disable_testpattern_sft_error;
   // uint8_t mars_write_mem_safe_sft_error;
   // uint8_t mars_read_mem_safe_sft_error;
   // uint8_t sft_error_unused_padding[3];
   // uint16_t mars_read_status_sft_error;
   // uint16_t mars_read_temperature_sft_error;
   // uint16_t mars_read_driver_status_sft_error;
   // uint16_t mars_read_bist_result_sft_error;
   // uint16_t mars_read_analog_diag_sft_error;
   // uint16_t mars_read_register_sft_error;
   // uint16_t mars_profiler_table_0_read_raw_sft_error;
   // uint16_t mars_profiler_table_1_read_raw_sft_error;
   uint16_t mars_profiler_table_0_write_raw_sft_error;
   uint16_t mars_profiler_table_1_write_raw_sft_error;
   uint16_t mars_configure_sft_error;
   uint16_t mars_trigger_frame_sft_error;
} MARS_SFT_Error_Counter_T;

typedef struct MARS_Bias_Write_Fail_Count_Tag
{
   uint8_t tx_bias_filter_chr_act_ctrl;
   uint8_t tx_bias_filter_mod_ctrl;
   uint8_t lodst_astxrx_bias_filter_ctrl;
   uint8_t lodst_asrx_bias_filter_ctrl;
   uint8_t lodst_astx_bias_filter_ctrl;
   uint8_t tx_vga_bias_filter_en;
   uint8_t tx_vga_bias_filter_speedup_dis;
   uint8_t tx_pr_bias_filter_en;
   uint8_t tx_pr_bias_filter_speedup_dis;
   uint8_t tx_pa_bias_filter_dis;
   uint8_t tx_bias_filter_chr_act_ctrl_post_tx;
   uint8_t rx_pissa_cbctrl;
   uint8_t lodst_tx_as_att;
   uint8_t lodst_astx_gain;
} MARS_Bias_Write_Fail_Count_T;

/* Read all current temperatures with state information */
typedef struct Mars_Temp_Update_Tag
{
   uint8_t temp_idx;
   uint8_t *state;
   float32_t *temperature;
} Mars_Temp_Update_T;

typedef struct
{
   int16_t temperature; /* cached sensor reading               */
   uint8_t enabled;     /* SMC enable flag (0 or 1)            */
   bool cw_mode;        /* true => excluded when !CW_MODE_FLAG */
} Temp_Sensor_Config_Entry_T;
typedef struct Register_Config_Tag
{
   uint32_t register_address; /*Register address to read/write*/
   uint32_t register_value;   /*Value to read/write*/
   bool data_confirm;         /*Flag to indicate if the register value is correct after write*/

} Register_Config_T;
/*===========================================================================*
 * Local File Scope Variables
 *===========================================================================*/
static mars_cal_control_t Calibration_Data_Place_Holder = {0xFFFFFFFFU, 0xFFFFFFFFU, 0xFFFFU}; /*ToDO: Sandeep - use SMC */
static volatile bool Is_CW_Mode_Enabled                 = false;
static volatile bool Is_Test_Pattern_Enabled            = false;
static volatile bool Is_Force_TX_Phase_LUT_Reload       = false;
volatile bool MMIC_XCP_BIST_Calib_Trigger               = false;
static char Func_Label[FUNC_LABEL_SIZE];
static mars_ssi_config_t Mars_Ssi_Config                       = MARS_SSI_QSPI;
static Mars_ReturnType API_Ret_Val                             = 0;
static uint16_t Frame_Counter                                  = 0U;
static mars_pt0_t Table_0_Raw[TABLE_0_ENTRIES_PER_LOOK]        = {0};
static mars_pt1_t Table_1_Raw[TABLE_1_ENTRIES_PER_LOOK]        = {0};
static mars_pt0_t Table_0_Raw_Return[TABLE_0_ENTRIES_PER_LOOK] = {0};
static mars_pt1_t Table_1_Raw_Return[TABLE_1_ENTRIES_PER_LOOK] = {0};

static uint8_t MMIC_Aptiv_Operation_Mode = MMIC_APTIV_OP_MODE_NORMAL;

/*Safe start-up implementation*/
static volatile uint8_t Sensor_Dead_Fault_Error_Count = 0U;
static volatile uint8_t MMIC_Sensor_Dead_Fault        = CODED_FALSE;

static volatile MMIC_Reg_RW_Custom_T MMIC_Custom_Reg_RW        = {MMIC_RW_CUSTOM_ACCESS_INVALID, NULL, 0, 0xFF};
static volatile MMIC_Memblk_RW_Custom_T MMIC_Custom_Memblk_RW  = {MMIC_RW_CUSTOM_ACCESS_INVALID, NULL, 0, 0xFF};
static volatile bool Is_Force_No_Verify_Tables                 = false;
static volatile bool Is_MIPI_Config_First_Time                 = true;
static MARS_SFT_Error_Counter_T MARS_SFT_Error_Counter         = {0};
static MARS_Bias_Write_Fail_Count_T MARS_Bias_Write_Fail_Count = {0};
static volatile uint8_t Meta_Data_Bytes[160];
static mars_meta_data_t Mars_Meta_Data_Read;
static volatile MMIC_Profiling_Times_T MMIC_Profiling_Times = {0};
static FuSa_Faults_Union_T MMIC_Fusa_Backup_Fault           = {0};
FuSa_Faults_Union_T MMIC_Fusa_Active_Fault                  = {0};
/*ZHV buffer Update variables for 2 stage implementation*/
static volatile uint32 Inter_ZHB_Data_Buffer[96] = {0};

#define MARS_RESET_TEST_DUE_TO_ERROR
#ifdef MARS_RESET_MECHANISM_ENABLED
static volatile bool MARS_Reset_Request = false;
MARS_Reset_Info_T MARS_Reset_Counters   = {0};
   #ifdef MARS_RESET_TEST_DUE_TO_ERROR
static volatile uint8_t complete_flip_test            = 0U;
static volatile uint8_t config_flip_test              = 0U;
static volatile uint8_t trigger_flip_test             = 0U;
static volatile uint8_t init_flip_test                = 0U;
static volatile uint8_t sft_flip_test                 = 0U;
static volatile bool Read_Write_Enable                = false;
volatile Register_Config_T Mars_Write_Register_Config = {0};
volatile Register_Config_T Mars_Read_Register_Config  = {0};
   #endif
#endif
/*Function Declaration for updating reg when OTP is above 10*/
void Update_Mars_Reg_From_OTP(void);

/* SM related functions*/
static void Handle_Bor_Power_Error(void);
static void Handle_Reference_Pll_Lock_Error(void);
static void Handle_MCU_Error(void);
static void Handle_Synthesizer_Error(void);
static void Handle_Rx_ADC_Error(void);
static void Handle_Frame_Unit_Error(void);
static void Handle_Async_Unit_Error(void);
static void Handle_Profiler_Unit_Error(void);
static void Handle_Enable_Unit_Error(void);
static void Handle_ADC_SYS_PLL_Lock_Error(void);
static void Handle_MCU_Subsystem_Error(void);
static void Handle_MIPI_Error(void);
static void Handle_SSI_Error(void);
static void Handle_Synthesizer_Lock_Error(void);
static void Handle_Safety_Unit_Error(void);
static void Handle_Safety_Error(void);

FuSa_Faults_Union_T *Get_Mmic_Fusa_Active_Fault_Ptr(void);
FuSa_Faults_Union_T *Get_Mmic_Fusa_Backup_Fault_Ptr(void);
mars_bist_result_t mars_bist_result_debug1 = {0};

#ifdef CMSIS_ENVIRONMENT
   #if defined(EDU_BOARD)
mars_instance_t Mars_Self_Layer2_InstanceDriver0 = {
   /* Mars Instance ID */
   MARS_INSTANCE_ID_0,
   /* Mars Data - no configuration option, data is initialized in mars_l2_action_init() */
   {{0}, {0}},
   /* Mars Drivers */
   {
      &r52_l0_ssi_edu, &r52_l0_gpio_reset_edu, &r52_l0_gpio_mlbx, &r52_l0_gpio_gp0, &r52_l0_gpio_sft, &r52_l0_oc, &r52_l0_tmr,
      &r52_l0_crc,
      #ifndef MARS_DEBUG_SUPPORT_DISABLED
      NULL_PTR /* TE pin not supported on EDU */
      #endif
   }};
   #elif defined(CHANDRA_EVB_BOARD)
mars_instance_t Mars_Self_Layer2_InstanceDriver0 = {
   /* Mars Instance ID */
   MARS_INSTANCE_ID_0,
   /* Mars Data - no configuration option, data is initialized in mars_l2_action_init() */
   {{0}, {0}},
   /* Mars Drivers */
   {
      &r52_l0_ssi_chandra_evb,
      #if defined(MARS_EVB_BOARD_T)
      &r52_l0_gpio_reset_chandra_evb_t,
      #else
   &r52_l0_gpio_reset_chandra_evb,
      #endif
      &r52_l0_gpio_mlbx, &r52_l0_gpio_gp0, &r52_l0_gpio_sft, &r52_l0_oc, &r52_l0_tmr, &r52_l0_crc,
      #ifndef MARS_DEBUG_SUPPORT_DISABLED
      NULL_PTR /* TE pin not supported on Chandra EVB */
      #endif
   }};
   #else
      #error "No Host board variant selected."
   #endif /* EDU_BOARD or CHANDRA_EVB_BOARD */
#endif    /* CMSIS_ENVIRONMENT */

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static Mars_ReturnType MARS_Log_Critical_Debug_Regs(void);
static Mars_ReturnType MARS_Log_Calibration_Regs(void);
static void MMIC_Custom_RW_Request(void);
static bool Mars_Register_Write_Custom(void);
static bool Mars_Register_Write_MDAC(void);
static void Clear_And_Copy(char *dest, size_t dest_size, const char *src);
static void Log_MMIC_Error(const char *message);
static bool Is_MMIC_Api_Fail(const Mars_ReturnType api_ret_val, const char *message);
static void Assemble_Tx_Control(uint32_t smc_value, uint8_t *tx_override, uint8_t *tx_control);
static uint32_t Pack_Tx_Control(uint8_t *tx_control);
static void MARS_SFT_Errors_Mon(void);
static void MMIC_Custom_RW_Request(void);
static void Clear_And_Copy(char *dest, size_t dest_size, const char *src);
static void MARS_SFT_Errors_Mon(void);
static void MMIC_FuSa_Backup_Active_Faults(void);
static void Update_Profiling_Time_Entry(volatile MMIC_Individual_Profiling_Times_T *entry, uint32_t current_time, bool first_time);
static bitfield32_t Get_Status_Based_On_Api_Fail(bool api_fail);
static bool MARS_Compare_Tables(uint32_t *a1, uint32_t *a2, uint32_t size);
static void MARS_Copy_Bist_Result(MMIC_Bist_Status_T *dest, const mars_bist_result_t *src);
static bool Rfe_Bist_Calibration_Trigger(void);
static void ZHV_Data_Update_From_Raw_Diagnostics(void);
static bool RFE_Look_Configure_Normal_Path(volatile MMIC_Config_Status_T *mmic_cfg_status_ptr,
                                           volatile MMIC_Individual_Profiling_Times_T *mmic_profiling_spec_config_ptr,
                                           bool *first_time_measurement_ptr);
static bool RFE_Look_Configure_CW_Path(mars_diag_t diag_values_for_temp[TEMP_DIAG_READ_QUANTITY]);
static bool MARS_Config_Write_Tables(uint64_t Look_Id, uint16_t starting_table_0_ind, uint16_t starting_table_1_ind,
                                     uint32_t *time_cal_ptr);
static bool MARS_Config_Configure_Look_Settings(uint64_t Look_Id, uint16_t Frame_Counter, bool *first_time_measurement_api_ptr);
static bool RFE_Initialization_Upload(MMIC_Sys_Status_T *init_sys_stat_ptr, MMIC_Temperature_Status_T *init_temp_stat_ptr,
                                      volatile MMIC_Profiling_Times_T *profile_ptr);
static bool RFE_Initialization_Activate(void);
static void Update_FSM_Mars_Errors(void);
/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/
static inline bool Multiple_Bit_Check(uint32_t value, uint32_t highest_bit, uint32_t step, uint32_t expected)
{
   uint32_t bit_idx;
   bool status = false;
   if (0U == step)
   {
      status = false;
   }

   for (bit_idx = 0U; bit_idx <= highest_bit; bit_idx += step)
   {
      if (DOUBLE_BIT_CHECK(value, bit_idx, expected))
      {
         status = true;
      }
   }

   return status;
}

/* Helper function: Sets all TxPhase fields based on phase_idx range matching.
 * Implements phase rotator calibration pattern with four mutually-exclusive ranges.
 * Each TX antenna gets its value only within its designated segment; others get 0U.
 */
static inline void Set_Phase_Values_For_Calibration(uint16_t phase_idx, uint16_t write_table0_idx)
{
   uint8_t phase_offset;

   Table_0_Raw[write_table0_idx].s.t0_2.TxPhase0 = 0U;
   Table_0_Raw[write_table0_idx].s.t0_2.TxPhase1 = 0U;
   Table_0_Raw[write_table0_idx].s.t0_2.TxPhase2 = 0U;
   Table_0_Raw[write_table0_idx].s.t0_3.TxPhase3 = 0U;

   if (phase_idx <= TXPHASE3_END)
   {
      phase_offset                                  = (uint8_t)(phase_idx - TXPHASE3_START);
      Table_0_Raw[write_table0_idx].s.t0_3.TxPhase3 = phase_offset;
   }
   else if (phase_idx <= TXPHASE2_END)
   {
      phase_offset                                  = (uint8_t)(phase_idx - TXPHASE2_START);
      Table_0_Raw[write_table0_idx].s.t0_2.TxPhase2 = phase_offset;
   }
   else if (phase_idx <= TXPHASE1_END)
   {
      phase_offset                                  = (uint8_t)(phase_idx - TXPHASE1_START);
      Table_0_Raw[write_table0_idx].s.t0_2.TxPhase1 = phase_offset;
   }
   else if (phase_idx <= TXPHASE0_END)
   {
      phase_offset                                  = (uint8_t)(phase_idx - TXPHASE0_START);
      Table_0_Raw[write_table0_idx].s.t0_2.TxPhase0 = phase_offset;
   }
}

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/
/*===========================================================================*\
 * FUNCTION: Mars_Write_Register_Value
 *===========================================================================*
 * RETURN VALUE:
 * uint8_t - Returns 0 on success, 1 on failure.
 *
 * PARAMETERS:
 * uint32_t reg      - Register identifier to write to MARS device.
 * uint32_t value    - Register value to write.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Writes a value to a register on the MARS device. On failure, increments
 * the failure counter for the corresponding register and returns 1.
 * On success, returns 0.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static uint8_t Mars_Write_Register_Value(uint32_t reg, const uint32_t value)
{
   uint8_t ret_val = 0U;
   Mars_ReturnType api_ret_val;
   bool api_fail;

   api_ret_val = mars_write_register(&Mars_Self_Layer2_InstanceDriver0, reg, value);
   api_fail    = Is_MMIC_Api_Fail(api_ret_val, "mars_write_register fail\n");
   if (api_fail)
   {
      ret_val = 1U;
   }
   else
   {
      ret_val = 0U;
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: Mars_Register_Write_MDAC
 *===========================================================================*
 * RETURN VALUE:
 * bool - Returns true if any MDAC register write fails, false otherwise.
 *
 * PARAMETERS:
 * None -
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Writes TX0..TX3 MDAC EN and MDAC INC registers with reset value 0x00
 * and reports API failures using the existing MMIC error helper.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static bool Mars_Register_Write_MDAC(void)
{
   uint16_t mdac_idx;
   const uint32_t mdac_regs[]  = {MARS_F_CORE_BANK_TX0_PR_MDAC_EN, MARS_F_CORE_BANK_TX0_PR_MDAC_INC,
                                 MARS_F_CORE_BANK_TX1_PR_MDAC_EN, MARS_F_CORE_BANK_TX1_PR_MDAC_INC,
                                 MARS_F_CORE_BANK_TX2_PR_MDAC_EN, MARS_F_CORE_BANK_TX2_PR_MDAC_INC,
                                 MARS_F_CORE_BANK_TX3_PR_MDAC_EN, MARS_F_CORE_BANK_TX3_PR_MDAC_INC};
   const char *mdac_err_msgs[] = {"Mars_Register_Write_TX0_PR_MDAC_EN fail\n", "Mars_Register_Write_TX0_PR_MDAC_INC fail\n",
                                  "Mars_Register_Write_TX1_PR_MDAC_EN fail\n", "Mars_Register_Write_TX1_PR_MDAC_INC fail\n",
                                  "Mars_Register_Write_TX2_PR_MDAC_EN fail\n", "Mars_Register_Write_TX2_PR_MDAC_INC fail\n",
                                  "Mars_Register_Write_TX3_PR_MDAC_EN fail\n", "Mars_Register_Write_TX3_PR_MDAC_INC fail\n"};
   bool api_fail               = false;

   for (mdac_idx = 0U; (mdac_idx < NUM_ELEMS(mdac_regs)) && (!api_fail); mdac_idx++)
   {
      API_Ret_Val = Mars_Write_Register_Value(mdac_regs[mdac_idx], 0x00U);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, mdac_err_msgs[mdac_idx]);
   }

   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: Mars_Read_Register_Value
 *===========================================================================*
 * RETURN VALUE:
 * Mars_ReturnType - Status of register read operation (E_OK or error code).
 *
 * PARAMETERS:
 * uint32_t reg_name           - Register identifier to read from MARS device.
 * uint32_t *mars_cal_reg_ptr  - Pointer to store the register value read.
 * uint8_t *fail_reg_mask_ptr  - Pointer to failure mask array; bit set if read fails.
 * uint16_t i                  - Register index for bit position in failure mask.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Reads a calibration register from the MARS device. On success, stores the
 * value at mars_cal_reg_ptr. On failure, sets the corresponding bit in the
 * failure mask array based on the register index i.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static Mars_ReturnType Mars_Read_Register_Value(uint32_t reg_name, uint32_t *mars_cal_reg_ptr, uint8_t *fail_reg_mask_ptr,
                                                uint16_t i)
{
   uint32_t reg_val = 0U;
   Mars_ReturnType api_ret_val;
   bool api_fail;

   api_ret_val = mars_read_register(&Mars_Self_Layer2_InstanceDriver0, reg_name, &reg_val);
   api_fail    = Is_MMIC_Api_Fail(api_ret_val, "mars_read_register failed\n");
   if (!api_fail)
   {
      *mars_cal_reg_ptr = reg_val;
   }
   else
   {
      if (fail_reg_mask_ptr != NULL)
      {
         fail_reg_mask_ptr[i / 8] |= (uint8_t)(1U << (i % 8));
      }
   }
   return api_ret_val;
}

/*==========================================================================*
* FUNCTION: Get_Status_Based_On_Api_Fail
*===========================================================================*
* RETURN VALUE:
* bitfield32_t - Returns 0 if API failed, 1 if API succeeded.
*
* PARAMETERS:
* bool api_fail - Boolean flag indicating API failure status.
* --------------------------------------------------------------------------
* ABSTRACT: Converts API failure status to a bitfield32_t status value.
* Returns 0 when api_fail is true (failure), 1 when api_fail is false (success).
* --------------------------------------------------------------------------
*
\*===========================================================================*/
static bitfield32_t Get_Status_Based_On_Api_Fail(bool api_fail)
{
   return api_fail ? (bitfield32_t)0 : (bitfield32_t)1;
}

/*===========================================================================*\
 * PHASE ROTATOR CALIBRATION MODE - CONSOLIDATED FUNCTIONS
 * All calibration-specific table 0 configuration functions grouped here
 * and only active when MMIC_Phase_Rotator_Calib_Mode is enabled.
 *===========================================================================*\
 */

/*===========================================================================*\
 * FUNCTION: Get_Calib_Fs
 *===========================================================================*
 * RETURN VALUE:
 * uint32_t - The Fs (frequency sweep) value for the given table 0 index, or
 *            0 if the index is out of range.
 *
 * PARAMETERS:
 * uint16_t idx - Table 0 entry index. Each block of 1024 entries maps to one
 *                of the four pre-defined Fs values.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Returns the Fs register value to be programmed into Table 0 during phase
 * rotator calibration mode. The 1024-entry period is divided into 4 blocks,
 * each assigned an alternating Fs value (8315405 / 8313961). Returns 0 for
 * any index beyond the 4 supported blocks.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static uint32_t Get_Calib_Fs(uint16_t idx)
{
   static const uint32_t fs_blocks[CALIB_FS_NUM_BLOCKS] = {CALIB_FS_VALUE_1, CALIB_FS_VALUE_2, CALIB_FS_VALUE_1, CALIB_FS_VALUE_2};
   uint16_t block                                       = idx / PHASE_ROTATOR_PATTERN_CYCLE;
   uint32_t fs_value                                    = 0U;

   if (block < CALIB_FS_NUM_BLOCKS)
   {
      fs_value = fs_blocks[block];
   }

   return fs_value;
}

/*===========================================================================*\
 * FUNCTION: Get_Calib_Tx_En
 *===========================================================================*
 * RETURN VALUE:
 * uint8_t - The TxEn bit-mask for the given table 0 index, or 0 if the index
 *           is out of range.
 *
 * PARAMETERS:
 * uint16_t idx - Table 0 entry index. Each block of 128 entries activates one
 *                TX antenna in sequence.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Returns the TX enable bitmask to be programmed into Table 0 during phase
 * rotator calibration mode. The 128-entry period activates a single TX at a
 * time in the order TX3 (8), TX2 (4), TX1 (2), TX0 (1), allowing independent
 * per-antenna phase characterisation. Returns 0 for any index beyond the 4
 * supported blocks.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static uint8_t Get_Calib_Tx_En(uint16_t idx)
{
   static const uint8_t tx_en_blocks[CALIB_FS_NUM_BLOCKS] = {CALIB_TX_EN_TX3, CALIB_TX_EN_TX2, CALIB_TX_EN_TX1, CALIB_TX_EN_TX0};
   uint16_t block                                         = idx / PHASE_ROTATOR_STEPS_PER_TX;
   uint8_t tx_en_value                                    = 0U;

   if (block < CALIB_FS_NUM_BLOCKS)
   {
      tx_en_value = tx_en_blocks[block];
   }

   return tx_en_value;
}

/*===========================================================================*\
 * FUNCTION: Configure_Phase_Rotator_Calib_Table_0
 *===========================================================================*
 * RETURN VALUE:
 * void - No return value. Directly configures Table_0_Raw entry.
 *
 * PARAMETERS:
 * uint16_t write_table0_idx - Index into Table_0_Raw for current entry
 * uint16_t ind              - Absolute table 0 index for calibration calculations
 * uint8_t *tx_control       - TX control array for TxEn assembly
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Comprehensive configuration of all table 0 fields during phase rotator
 * calibration mode. Consolidates Fs, RxEnAntAB, Td, TxEn, and TxPhase
 * setup into a single function under MMIC_Phase_Rotator_Calib_Mode condition.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Configure_Phase_Rotator_Calib_Table_0(uint16_t write_table0_idx, uint16_t ind, uint8_t *tx_control)
{
   uint32_t tx_SMC_value;
   uint32_t packedNum;
   uint16_t phase_idx;

   /* Configure Fs (frequency sweep) with alternating pattern */
   Table_0_Raw[write_table0_idx].s.t0_0.Fs = Get_Calib_Fs(ind);

   /* Configure RxEnAntAB and Td (timing delay) for calibration mode */
   Table_0_Raw[write_table0_idx].s.t0_0.RxEnAntAB = CALIB_RX_EN_ANT_AB_PATTERN;
   Table_0_Raw[write_table0_idx].s.t0_1.Td = (ind < CALIB_TD_THRESHOLD_INDEX) ? CALIB_TD_DELAY_ACTIVE : CALIB_TD_DELAY_INACTIVE;

   /* Configure Ts (sampling time) */
   Table_0_Raw[write_table0_idx].s.t0_1.Ts = mars_table_0_ts_smc[ind];

   /* Configure TxEn (TX enable mask) with sequential TX activation */
   tx_SMC_value = Get_Calib_Tx_En(write_table0_idx);
   Assemble_Tx_Control(tx_SMC_value, aptiv_tx_override_smc, tx_control);
   packedNum                                 = Pack_Tx_Control(tx_control);
   Table_0_Raw[write_table0_idx].s.t0_1.TxEn = packedNum;

   /* Configure ChirpMode and T1Ptr */
   Table_0_Raw[write_table0_idx].s.t0_2.ChirpMode = mars_table_0_chirp_mode_smc[ind];
   Table_0_Raw[write_table0_idx].s.t0_2.T1Ptr     = mars_table_0_t1_ptr_smc[ind];

   /* Configure TxPhase values for calibration pattern */
   phase_idx = (uint16_t)(write_table0_idx % PHASE_ROTATOR_PATTERN_CYCLE);
   Set_Phase_Values_For_Calibration(phase_idx, write_table0_idx);
}

/*===========================================================================*
* FUNCTION: Log_MMIC_Error
*===========================================================================*
* RETURN VALUE:
* void - No return value.
*
* PARAMETERS:
* const char *message - Error message to log via UART.
* --------------------------------------------------------------------------
* ABSTRACT: Copies message into a local buffer and sends it through UART
* for MMIC error reporting.
* --------------------------------------------------------------------------
*
\*===========================================================================*/
static void Log_MMIC_Error(const char *message)
{
   Clear_And_Copy(Func_Label, sizeof(Func_Label), message);
   UART_SEND_WRAP(Func_Label, sizeof(Func_Label), 0);
}

/*===========================================================================*\
 * FUNCTION: Is_MMIC_Api_Fail
 *===========================================================================*
 * RETURN VALUE:
 * bool - Returns true if API error occurred, false if no error.
 *
 * PARAMETERS:
 * const Mars_ReturnType api_ret_val - Return value from MARS API call.
 * const char *message               - Error message to log via UART if error detected.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Checks if API call resulted in an error by masking against
 * API_ONLY_ERROR_MASK. If error detected, logs the provided message via
 * UART and returns true; otherwise returns false.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static bool Is_MMIC_Api_Fail(const Mars_ReturnType api_ret_val, const char *message)
{
   bool api_fail;
   if (E_OK != (api_ret_val & API_ONLY_ERROR_MASK))
   {
      Log_MMIC_Error(message);
      api_fail = true;
   }
   else
   {
      api_fail = false;
   }
   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: Uart_SendData_Dummy
 *===========================================================================*
 * RETURN VALUE:
 * void - No return value.
 *
 * PARAMETERS:
 * const void *const data   - Pointer to data buffer (unused).
 * uint32_t len             - Length of data (unused).
 * Uart_ChannelType channel - UART channel identifier (unused).
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Dummy UART send function used when DEVELOP_UART is disabled. This function
 * provides a no-op replacement for Uart_SendData to allow compilation without
 * actual UART debug output. All parameters are cast to void to suppress
 * unused parameter warnings.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Uart_SendData_Dummy(const void *const data, uint32_t len, Uart_ChannelType channel)
{
   (void)data;
   (void)channel;
}

void MARS_DEBUG_Check_Phase_LUT(uint16_t *Mars_Phase_LUT, uint16_t *lut_values)
{
   /*V1 of the spec has this not implemented*/
}

/*
static float32_t Round_Custom(float32_t x)
{
   if (x < 0.0)
   {
      return (int)(x - 0.5);
   }
   else
   {
      return (int)(x + 0.5);
   }
} */

/*===========================================================================*\
 * FUNCTION: MARS_Startup_Config
 *===========================================================================*
 * RETURN VALUE:
 * Mars_ReturnType - Status of LUT programming and startup config.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT: Programs the phase LUT and updates startup configuration status
 * flags based on the outcome.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType MARS_Startup_Config(void)
{
   MMIC_Config_Status_T *mmic_cfg_status_ptr = &MMIC_Stream.MMIC_Data.mmic_config_status;
   bool api_fail                             = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   if (flag_mmic_phase_lut_valid_USC)
   {
      API_Ret_Val = mars_phase_lut_write_raw(&Mars_Self_Layer2_InstanceDriver0, k_mmic_phase_lut_USC);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "lut_write_raw fail\n");
   }
   if (!api_fail)
   {
      API_Ret_Val = mars_phase_lut_read_raw(&Mars_Self_Layer2_InstanceDriver0, k_mmic_phase_lut_USC);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "lut_read_raw fail\n");
   }

   mmic_cfg_status_ptr->mars_startup_config_status = Get_Status_Based_On_Api_Fail(api_fail);

   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: MARS_ZHB_Initialization
 *===========================================================================*
 * RETURN VALUE:
 * Mars_ReturnType - See implementation for initialization outcome.
 *
 * PARAMETERS:
 * Refer to signature for parameter usage.
 * --------------------------------------------------------------------------
 * ABSTRACT: Auto-generated placeholder documenting ZHB initialization stub.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType MARS_ZHB_Initialization(void)
{
   bool api_fail = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   if (flag_zhb_calibration_USC)
   {
      MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.zhb_enabled_in_usc = 1U;
      API_Ret_Val = mars_zhv_write(&Mars_Self_Layer2_InstanceDriver0, zhb_calibration_lut_USC);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "ZHB Write failed\n");
      if (!api_fail)
      {
         API_Ret_Val = mars_zhv_read(&Mars_Self_Layer2_InstanceDriver0, ZHB_Data_From_MARS); /*h data from Mars*/
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "ZHB Read failed\n");
      }

      if (!api_fail)
      {
         if (0 != memcmp(&ZHB_Data_From_MARS, &zhb_calibration_lut_USC, sizeof(zhb_calibration_lut_USC)))
         {
            API_Ret_Val = E_NOT_OK;
            api_fail    = true;
            Log_MMIC_Error("ZHB compare failed\n");
         }
      }

      memcpy(&MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.zhv_data_array, &zhb_calibration_lut_USC,
             sizeof(zhb_calibration_lut_USC));
   }
   else
   {
      MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.zhb_enabled_in_usc = 0U;
   }
   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: RFE_Initialization_Upload
 *===========================================================================*
 * RETURN VALUE:
 * bool - Returns true if an API error occurred, false otherwise.
 *
 * PARAMETERS:
 * MMIC_Sys_Status_T *init_sys_stat_ptr          - Pointer to init system status output.
 * MMIC_Temperature_Status_T *init_temp_stat_ptr - Pointer to init temperature status output.
 * volatile MMIC_Profiling_Times_T *profile_ptr  - Pointer to profiling times output.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Executes the first stage of RFE initialization: MARS init, status read,
 * QSPI config, PVT setup/read, and firmware upload from flash.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static bool RFE_Initialization_Upload(MMIC_Sys_Status_T *init_sys_stat_ptr, MMIC_Temperature_Status_T *init_temp_stat_ptr,
                                      volatile MMIC_Profiling_Times_T *profile_ptr)
{
   mars_rdrstatus_t rdr_status = {0};
   uint32_t time_cal           = Measurement_debug_timer_ms;
   uint32_t maf_offset         = 0; /* Start offset for data transfer */
   uint32_t total_size         = MAF_DATA_SIZE;
   uint16_t pvt_cfg_idx;
   const uint32_t pvt_cfg_regs[] = {MARS_F_CORE_BANK_SFT_PVT_SAMPLE_SIZE, MARS_F_CORE_BANK_SFT_PVT_START_SAMPLING,
                                    MARS_F_CORE_BANK_SFT_PVT_START_SAMPLING};
   const uint32_t pvt_cfg_vals[] = {0x06U, 0x01U, 0x00U};
   bool api_fail                 = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   if (!api_fail)
   {
      API_Ret_Val                          = MARS_INIT(&Mars_Self_Layer2_InstanceDriver0);
      profile_ptr->api_initialisation_time = Measurement_debug_timer_ms - time_cal;
      api_fail                             = Is_MMIC_Api_Fail(API_Ret_Val, "mars_init fail\n");
   }

   if (!api_fail)
   {
      API_Ret_Val = mars_read_status(&Mars_Self_Layer2_InstanceDriver0, &rdr_status);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_status init fail\n");

      init_sys_stat_ptr->sft_error   = rdr_status.sft_error;
      init_sys_stat_ptr->mcu_status  = rdr_status.mcu_status;
      init_sys_stat_ptr->ctrl_status = (uint8_t)rdr_status.ctrl_status;
   }

   if (!api_fail)
   {
      Mars_Ssi_Config = MARS_SSI_QSPI; // setting this config state to qspi rather than SPI
      API_Ret_Val     = mars_qspi_config(&Mars_Self_Layer2_InstanceDriver0, &Mars_Ssi_Config);
      api_fail        = Is_MMIC_Api_Fail(API_Ret_Val, "mars_qspi_config fail\n");
   }
   if (!api_fail)
   {
      for (pvt_cfg_idx = 0U; (pvt_cfg_idx < NUM_ELEMS(pvt_cfg_regs)) && (!api_fail); pvt_cfg_idx++)
      {
         API_Ret_Val = Mars_Write_Register_Value(pvt_cfg_regs[pvt_cfg_idx], pvt_cfg_vals[pvt_cfg_idx]);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_write_register fail\n");
      }
   }

   /* Check to see that the measurement has completed */
   if (!api_fail)
   {
      uint32_t busy_val  = 1U;
      int time_out_count = 0;
      do
      {
         API_Ret_Val = mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_CORE_BANK_SFT_PVT_BUSY, &busy_val);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_register busy fail\n");
         if (api_fail || (busy_val == 0U))
         {
            break;
         }
         time_out_count++;
      } while (time_out_count < MAX_TIME_OUT_COUNT);

      if (time_out_count == MAX_TIME_OUT_COUNT)
      {
         API_Ret_Val = E_NOT_OK;
      }
   }
   /*retrive the PVT sensor reading*/
   if (!api_fail)
   {
      uint32_t pvt_avg_value = 0U;
      API_Ret_Val = mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_CORE_BANK_SFT_PVT_AVG_VALUE, &pvt_avg_value);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_register PVT_AVG_VALUE fail\n");

      if (!api_fail)
      {
         const double pvt_raw_code           = (double)(pvt_avg_value & MARS_PVT_AVG_VALUE_MASK);
         init_temp_stat_ptr->temperature_pvt = MARS_PVT_POLYNOMIAL_TEMP_DEGC(pvt_raw_code);
      }
   }

   time_cal = Measurement_debug_timer_ms;

   if (!api_fail)
   {
      int32_t ReadData_result = 0;
      uint8_t read_buffer_mars[CHUNK_SIZE] __attribute__((aligned(16)));
      static int16_t calib_timeout_counter;
      uint32_t uint32_array[CHUNK_SIZE / 4] = {0};
      uint8_t *data_ptr                     = (uint8_t *)__MARS_FW_FLASH_START_ADDRESS;
      while (total_size > 0)
      {
         uint32_t chunk_size   = (total_size < CHUNK_SIZE) ? total_size : CHUNK_SIZE;
         calib_timeout_counter = 1000;
         ReadData_result       = Fls_Read((uint32_t)data_ptr, read_buffer_mars, chunk_size);
         if (E_OK == ReadData_result)
         {
            do
            {
               Fls_MainFunction();
               calib_timeout_counter--;
            } while ((MEMIF_JOB_PENDING == Fls_GetJobResult()) && (calib_timeout_counter));

            if ((MEMIF_JOB_OK != Fls_GetJobResult()) || (0 == calib_timeout_counter))
            {
               API_Ret_Val = E_NOT_OK;
            }

            if (E_OK != API_Ret_Val) // This should remain the same
            {
               Log_MMIC_Error("mars_upload_firmware fetch fail\n");
               break;
            }

            // Convert 1024 bytes to 256 uint32_t values
            for (int i = 0; i < (CHUNK_SIZE / 4); i++)
            {
               uint32_array[i] = (uint32_t)read_buffer_mars[i * 4 + 3] << 24 | (uint32_t)read_buffer_mars[i * 4 + 2] << 16 |
                                 (uint32_t)read_buffer_mars[i * 4 + 1] << 8 | (uint32_t)read_buffer_mars[i * 4];
            }

            API_Ret_Val = mars_upload_firmware(&Mars_Self_Layer2_InstanceDriver0, uint32_array, maf_offset, chunk_size);
            api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_upload_firmware fail\n");
            if (api_fail)
            {
               break;
            }
            /* Move to the next chunk */
            maf_offset += chunk_size;
            total_size -= chunk_size;
            data_ptr += chunk_size;
         }
         else
         {
            API_Ret_Val = E_NOT_OK;
            break;
         }
      }
      api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "Fls firmware load fail\n");
   }

   profile_ptr->api_firmware_upload_time = Measurement_debug_timer_ms - time_cal;

   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: RFE_Initialization_Activate
 *===========================================================================*
 * RETURN VALUE:
 * bool - Returns true if an API error occurred, false otherwise.
 *
 * PARAMETERS:
 * None -
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Executes the second stage of RFE initialization: custom register writes,
 * firmware activation, SFT/BIST checks, metadata programming, and MDAC updates.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static bool RFE_Initialization_Activate(void)
{
   mars_activation_t activation_type                 = ACTIVATE_CHECK_CRC;
   uint32_t time_cal                                 = Measurement_debug_timer_ms;
   mars_diag_t diag_values[OTP_ID_DIAG_MEM_QUANTITY] = {{0}};
   bool api_fail                                     = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   if (!api_fail)
   {
      api_fail = Mars_Register_Write_Custom();
   }

   if (!api_fail)
   {
      /*Sandeep: fetch the activation type from SMC when the SMC has value 1(with crc check) which is the only one supported now*/
      /*activation_type                                 = mars_firmware_activation_type_smc;*/
      time_cal                                        = Measurement_debug_timer_ms;
      API_Ret_Val                                     = mars_activate_firmware(&Mars_Self_Layer2_InstanceDriver0, activation_type);
      MMIC_Profiling_Times.api_firmware_activate_time = Measurement_debug_timer_ms - time_cal;
      api_fail                                        = Is_MMIC_Api_Fail(API_Ret_Val, "mars_activate_firmware fail\n");
   }

   /* This is to enable debugging if  SFT MM_ERROR pin is asserted by Mars */
   if (!api_fail)
   {
      API_Ret_Val = mars_read_bist_result(&Mars_Self_Layer2_InstanceDriver0, &mars_bist_result_debug1);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_bist_result fail in Init \n");
   }

   if (!api_fail)
   {
      API_Ret_Val = mars_check_sft_pin(&Mars_Self_Layer2_InstanceDriver0);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_check_sft_pin fail\n");
   }

   if (!api_fail)
   {
      API_Ret_Val = MARS_REG_WRITE();
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_REG_WRITE fail\n");
   }

   if (!api_fail)
   {
      API_Ret_Val = Mars_Register_Write_MetaData_Packet_Type();
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "Mars_Register_Write_MetaData_Packet_Type fail\n");
   }
   /* MDAC register update */
   if (!api_fail)
   {
      /* OTP version comes from diagnostic memory index 448 */
      API_Ret_Val      = mars_read_diag_raw(&Mars_Self_Layer2_InstanceDriver0, 448u, OTP_ID_DIAG_MEM_QUANTITY, diag_values);
      Mars_OTP_Version = diag_values[0].raw_value;
      api_fail         = Is_MMIC_Api_Fail(API_Ret_Val, "Mars_Read_Diag_Raw fail\n");
   }

   if (!api_fail && (OPT_HW_VERSION_THRESHOLD_FOR_MDAC > Mars_OTP_Version))
   {
      api_fail = Mars_Register_Write_MDAC();
   }

   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: RFE_Initialization
 *===========================================================================*
 * RETURN VALUE:
 * Mars_ReturnType - Status of MMIC radio front-end initialization sequence.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT: Performs the MMIC radio front-end initialization sequence,
 * including MARS init, status readback, SSI configuration, firmware upload
 * from flash, custom register writes, firmware activation, safety pin check,
 * and metadata/register programming. Updates MMIC configuration and system
 * status structures with the outcome.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType RFE_Initialization(void)
{
   MMIC_Sys_Status_T *init_sys_stat_ptr          = &(MMIC_Stream.MMIC_Data.init_sys_status);
   MMIC_Config_Status_T *mmic_cfg_stat_ptr       = &(MMIC_Stream.MMIC_Data.mmic_config_status);
   volatile MMIC_Profiling_Times_T *profile_ptr  = &MMIC_Profiling_Times;
   MMIC_Temperature_Status_T *init_temp_stat_ptr = &(MMIC_Stream.MMIC_Data.init_temp_status);
   bool api_fail                                 = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   MMIC_Stream.MMIC_Data.MMIC_fault_status.MMIC_system_start_status.MMIC_system_start_fault = CODED_FALSE;

   switch (MMIC_RFE_Init_State)
   {
      case MMIC_RFE_INIT_UPLOAD_THEN_ACTIVATE:
         api_fail = RFE_Initialization_Upload(init_sys_stat_ptr, init_temp_stat_ptr, profile_ptr);
         if (!api_fail)
         {
            api_fail = RFE_Initialization_Activate();
            if (!api_fail)
            {
               MMIC_RFE_Init_State = MMIC_RFE_INIT_ACTIVATE_ONLY;
            }
            else
            {
               /*this is the good case and moved to default value: this variable will be overwritten by mars_reset */
               MMIC_RFE_Init_State = MMIC_RFE_INIT_UPLOAD_ONLY;
            }
         }
         else
         {
            MMIC_RFE_Init_State = MMIC_RFE_INIT_UPLOAD_ONLY;
         }
         break;

      case MMIC_RFE_INIT_UPLOAD_ONLY_WITH_RESET_RETRY:
         (void)MARS_Reset(); /* Retry reset before upload on startup failure path */
         api_fail = RFE_Initialization_Upload(init_sys_stat_ptr, init_temp_stat_ptr, profile_ptr);
         if (!api_fail)
         {
            MMIC_RFE_Init_State = MMIC_RFE_INIT_ACTIVATE_ONLY;
         }
         else
         {
            MMIC_RFE_Init_State = MMIC_RFE_INIT_UPLOAD_ONLY_WITH_RESET_RETRY;
         }
         break;

      case MMIC_RFE_INIT_UPLOAD_ONLY:
         api_fail = RFE_Initialization_Upload(init_sys_stat_ptr, init_temp_stat_ptr, profile_ptr);
         if (!api_fail)
         {
            MMIC_RFE_Init_State = MMIC_RFE_INIT_ACTIVATE_ONLY;
         }
         else
         {
            MMIC_RFE_Init_State = MMIC_RFE_INIT_UPLOAD_ONLY_WITH_RESET_RETRY;
         }
         break;

      case MMIC_RFE_INIT_ACTIVATE_ONLY:
      default:
         api_fail = RFE_Initialization_Activate();
         break;
   }

   mmic_cfg_stat_ptr->mars_initialization_status = Get_Status_Based_On_Api_Fail(api_fail);

   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: MARS_Log_Static_Parameters
 *===========================================================================*
 * RETURN VALUE:
 * Mars_ReturnType - See implementation for logging outcome.
 *
 * PARAMETERS:
 * Refer to signature for parameter usage.
 * --------------------------------------------------------------------------
 * ABSTRACT: Auto-generated placeholder documenting static parameter logging.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType MARS_Log_Static_Parameters(void)
{
   mars_rdrstatus_t rdr_status = {0};

   mars_driver_status_t mars_driver_status   = 0U;
   mars_api_sw_version_t mars_api_sw_version = {0};

   MMIC_Device_Id_T *mmic_device_id_ptr = &(MMIC_Stream.MMIC_Data.otp_die_id);
   MMIC_Data_Logging_T *mmic_data_ptr   = &(MMIC_Stream.MMIC_Data);
   MMIC_Sys_Status_T *init_sys_stat_ptr = &(MMIC_Stream.MMIC_Data.init_sys_status);

   bool api_fail = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   /*Removed mars_update_diagnostic_values & mars_read_diag_raw &temperature sensors read , Look complete will have the sensor data
    * in runtime*/

   if (!api_fail)
   {
      API_Ret_Val = mars_read_status(&Mars_Self_Layer2_InstanceDriver0, &rdr_status);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_status fail\n");
      if (!api_fail)
      {
         init_sys_stat_ptr->sft_error   = rdr_status.sft_error;
         init_sys_stat_ptr->mcu_status  = rdr_status.mcu_status;
         init_sys_stat_ptr->ctrl_status = (uint8_t)rdr_status.ctrl_status;
      }
   }

   if (!api_fail)
   {
      API_Ret_Val = mars_read_driver_status(&Mars_Self_Layer2_InstanceDriver0, &mars_driver_status);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_driver_status fail\n");
      if (!api_fail)
      {
         MMIC_Stream.MMIC_Data.mars_driver_status = (uint32_t)mars_driver_status;
      }
   }

   if (!api_fail)
   {
      API_Ret_Val = mars_read_uid(&Mars_Self_Layer2_InstanceDriver0, &Mars_UID);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_uid fail\n");
      if (!api_fail)
      {
         /* Split 64-bit si_version into two 32-bit fields for 4-byte alignment */
         mmic_device_id_ptr->si_version_lower = UINT64_TO_LOWER32(Mars_UID.si_name_version);
         mmic_device_id_ptr->si_version_upper = UINT64_TO_UPPER32(Mars_UID.si_name_version);

         mmic_device_id_ptr->fw_version = Mars_UID.fw_version.maf_version;

         /* Split 64-bit chip_id into two 32-bit fields for 4-byte alignment */
         mmic_device_id_ptr->chip_id_lower = UINT64_TO_LOWER32(Mars_UID.uid);
         mmic_device_id_ptr->chip_id_upper = UINT64_TO_UPPER32(Mars_UID.uid);
      }
   }

   if (!api_fail)
   {
      API_Ret_Val = mars_get_api_version(&Mars_Self_Layer2_InstanceDriver0, &mars_api_sw_version);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_get_api_version fail\n");

      mmic_data_ptr->mmic_config_status.mars_static_params_read_status = Get_Status_Based_On_Api_Fail(api_fail);
      if (!api_fail)
      {
         mmic_data_ptr->api_version.major = mars_api_sw_version.major;
         mmic_data_ptr->api_version.minor = mars_api_sw_version.minor;
         mmic_data_ptr->api_version.patch = mars_api_sw_version.patch;
      }
   }
   else
   {
      mmic_data_ptr->mmic_config_status.mars_static_params_read_status = 0U;
   }
   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: MARS_Start_CW_Mode
 *===========================================================================
 * RETURN VALUE:
 * Mars_ReturnType API_Ret_Val - Status of CW start operations.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT: Configures CW mode look, computes TX enable mask, and starts
 * continuous wave on enabled TX paths with requested phase/frequency.
 * Updates configuration status and logs failures.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType MARS_Start_CW_Mode(void)
{
   uint8_t tx_control_value = 0;
   uint8_t tx_enable_cw[MARS_NUM_TX_PORTS];
   uint8_t tx_idx;
   uint8_t look_id;
   MMIC_Config_Status_T *mmic_cfg_status_ptr        = &MMIC_Stream.MMIC_Data.mmic_config_status;
   bool api_fail                                    = Is_MMIC_Api_Fail(API_Ret_Val, __func__);
   const char *start_cw_err_msgs[MARS_NUM_TX_PORTS] = {"mars_start_cw 0 fail\n", "mars_start_cw 1 fail\n",
                                                       "mars_start_cw 2 fail\n", "mars_start_cw 3 fail\n"};

   /*if CW is already running halt all CW opperation before starting*/
   // if (!api_fail))
   // {
   /* Need to Discuss with Systems team whether this is needed.*/
   /* API_Ret_Val = MARS_Stop_CW_Mode();
      api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "Stop CW mode in Start CW fail\n"); */
   // }

   if (!api_fail)
   {
      /*MARS CONFIG*/
      look_id     = aptiv_cw_mode_index_smc;
      API_Ret_Val = MARS_Config(look_id, Frame_Counter);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "Config in Start CW fail\n");
   }

   tx_control_value = aptiv_tx_control_mask_smc[aptiv_cw_mode_index_smc];
   for (tx_idx = 0U; tx_idx < MARS_NUM_TX_PORTS; tx_idx++)
   {
      tx_enable_cw[tx_idx] = GET_BIT(tx_control_value, tx_idx);
   }

   for (tx_idx = 0U; (tx_idx < MARS_NUM_TX_PORTS) && (!api_fail); tx_idx++)
   {
      if (tx_enable_cw[tx_idx])
      {
         mars_raw_phase_t mars_raw_phase = mars_pcw_phase_smc[tx_idx];
         API_Ret_Val                     = mars_start_cw(&Mars_Self_Layer2_InstanceDriver0, tx_idx, mars_raw_phase,
                                                         (mars_fs_frequency_t)mars_pcw_start_frequency_smc);
         api_fail                        = Is_MMIC_Api_Fail(API_Ret_Val, start_cw_err_msgs[tx_idx]);
      }
   }

   mmic_cfg_status_ptr->mars_start_cw_mode_status = Get_Status_Based_On_Api_Fail(api_fail);

   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: MARS_Stop_CW_Mode
 *===========================================================================
 * RETURN VALUE:
 * Mars_ReturnType API_Ret_Val - Status of CW stop operations.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT: Stops continuous wave generation on all TX paths. Updates
 * configuration status and logs any failures per TX channel.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType MARS_Stop_CW_Mode(void)
{
   uint8_t tx_idx;
   MMIC_Config_Status_T *mmic_cfg_status_ptr       = &MMIC_Stream.MMIC_Data.mmic_config_status;
   bool api_fail                                   = Is_MMIC_Api_Fail(API_Ret_Val, __func__);
   const char *stop_cw_err_msgs[MARS_NUM_TX_PORTS] = {"mars_stop_cw_TX0 fail\n", "mars_stop_cw_TX1 fail\n",
                                                      "mars_stop_cw_TX2 fail\n", "mars_stop_cw_TX3 fail\n"};

   for (tx_idx = 0U; (tx_idx < MARS_NUM_TX_PORTS) && (!api_fail); tx_idx++)
   {
      API_Ret_Val = mars_stop_cw(&Mars_Self_Layer2_InstanceDriver0, tx_idx);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, stop_cw_err_msgs[tx_idx]);
   }

   mmic_cfg_status_ptr->mars_stop_cw_mode_status = Get_Status_Based_On_Api_Fail(api_fail);

   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: MARS_Start_Test_Pattern_Mode
 *===========================================================================
 * RETURN VALUE:
 * Mars_ReturnType API_Ret_Val - Status of test pattern enable operations.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT: Configures and enables test pattern generation on all ADC
 * channels using per-channel configurations. Updates status and logs
 * failures.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType MARS_Start_Test_Pattern_Mode(void)
{
   MMIC_Config_Status_T *mmic_cfg_status_ptr = &MMIC_Stream.MMIC_Data.mmic_config_status;
   bool api_fail                             = Is_MMIC_Api_Fail(API_Ret_Val, __func__);
   mars_tp_config_t tp_config_ch1            = {MARS_TP_SINE, MARS_TP_PRBS7, MARS_TP_PAR12, 512, 1, 0, 0, 0};
   mars_tp_config_t tp_config_ch2            = {MARS_TP_PULSE, MARS_TP_PRBS7, MARS_TP_PAR12, 0, 0, 0, 0, 0};
   mars_tp_config_t tp_config_ch3            = {MARS_TP_RAMP, MARS_TP_PRBS7, MARS_TP_PAR12, 512, 1, 0, 0, 0};
   mars_tp_config_t tp_config_ch4            = {MARS_TP_PRBS, MARS_TP_PRBS7, MARS_TP_PAR12, 0, 1, 0, 0, 0};

   if (!api_fail)
   {
      API_Ret_Val =
         mars_enable_testpattern(&Mars_Self_Layer2_InstanceDriver0, 0, &tp_config_ch1, MARS_TESTPATTERN_CLR_SAMPLE_START);
      API_Ret_Val |=
         mars_enable_testpattern(&Mars_Self_Layer2_InstanceDriver0, 1, &tp_config_ch2, MARS_TESTPATTERN_CLR_SAMPLE_START);
      API_Ret_Val |=
         mars_enable_testpattern(&Mars_Self_Layer2_InstanceDriver0, 2, &tp_config_ch3, MARS_TESTPATTERN_CLR_SAMPLE_START);
      API_Ret_Val |=
         mars_enable_testpattern(&Mars_Self_Layer2_InstanceDriver0, 3, &tp_config_ch4, MARS_TESTPATTERN_CLR_SAMPLE_START);

      api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "Enable Test Pattern fail\n");

      mmic_cfg_status_ptr->mars_start_test_pattern_status = Get_Status_Based_On_Api_Fail(api_fail);
   }

   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: MARS_Stop_Test_Pattern_Mode
 *===========================================================================
 * RETURN VALUE:
 * Mars_ReturnType API_Ret_Val - Status of test pattern disable operations.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT: Disables test pattern generation for all ADC channels, updates
 * configuration status, and logs any failures.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType MARS_Stop_Test_Pattern_Mode(void)
{
   MMIC_Config_Status_T *mmic_cfg_status_ptr = &MMIC_Stream.MMIC_Data.mmic_config_status;
   bool api_fail                             = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   if (!api_fail)
   {
      API_Ret_Val = mars_disable_testpattern(&Mars_Self_Layer2_InstanceDriver0, MARS_ADC_CH1);
      API_Ret_Val |= mars_disable_testpattern(&Mars_Self_Layer2_InstanceDriver0, MARS_ADC_CH2);
      API_Ret_Val |= mars_disable_testpattern(&Mars_Self_Layer2_InstanceDriver0, MARS_ADC_CH3);
      API_Ret_Val |= mars_disable_testpattern(&Mars_Self_Layer2_InstanceDriver0, MARS_ADC_CH4);
      api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "Disable Test Pattern fail\n");

      mmic_cfg_status_ptr->mars_stop_test_pattern_status = Get_Status_Based_On_Api_Fail(api_fail);
   }
   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Temp_Report
 *===========================================================================
 * RETURN VALUE:
 *    void
 * PARAMETERS:
 *    MMIC_Temperature_Status_T *mmic_temp_ptr
 * --------------------------------------------------------------------------
 * ABSTRACT: This function updates MARS Temp
 * --------------------------------------------------------------------------
\*===========================================================================*/
void Get_MMIC_Temp_Report(void)
{
   volatile MARS_Temparature_Data_T *mars_temp_data = Get_MARS_Temp_Report();

   /* Tx0 Temperature Sensor */
   mars_temp_data->tmp_tx0_sens = (int16_t)MMIC_Stream.MMIC_Data.current_temp_status.temperature_tx0;
   /* Tx1 Temperature Sensor */
   mars_temp_data->tmp_tx1_sens = (int16_t)MMIC_Stream.MMIC_Data.current_temp_status.temperature_tx1;
   /* Tx2 Temperature Sensor */
   mars_temp_data->tmp_tx2_sens = (int16_t)MMIC_Stream.MMIC_Data.current_temp_status.temperature_tx2;
   /* Tx3 Temperature Sensor */
   mars_temp_data->tmp_tx3_sens = (int16_t)MMIC_Stream.MMIC_Data.current_temp_status.temperature_tx3;
   /* PVT Temperature Sensor */
   mars_temp_data->tmp_pvt_sens = (int16_t)MMIC_Stream.MMIC_Data.current_temp_status.temperature_pvt;
   /* PVT tsens Temperature Sensor */
   mars_temp_data->tmp_pvt_tsens = (int16_t)MMIC_Stream.MMIC_Data.current_temp_status.temperature_pvt_tsense;
   /* RX Temperature Sensor */
   mars_temp_data->tmp_rx0_sens = (int16_t)MMIC_Stream.MMIC_Data.current_temp_status.temperature_rx_tsense_gen;
   /* Quad Temperature Sensor */
   mars_temp_data->tmp_quad_sens = (int16_t)MMIC_Stream.MMIC_Data.current_temp_status.temperature_quad_tsense_gen;
}

/*===========================================================================*\
 * FUNCTION: Get_RF_Inject_RX_Diag_Raw_Value_Ptr
 *===========================================================================
 * RETURN VALUE:
 *    MMIC_Analog_Bist_Status_T * - Pointer to the first diagnostic entry in
 *                                  the RF Inject RX range [250, 281].
 * --------------------------------------------------------------------------
 * ABSTRACT: Returns a pointer to mmic_diag_values[250].
 * The caller iterates ptr[i].raw_value for i = 0 to 31 to access
 * all RF Inject RX raw values for CAN population.
 * --------------------------------------------------------------------------
\*===========================================================================*/
MMIC_Analog_Bist_Status_T *Get_RF_Inject_RX_Diag_Raw_Value_Ptr(void)
{
   return &MMIC_Stream.MMIC_Data.mmic_diag_values[250U];
}

/*===========================================================================*\
 * FUNCTION: Get_RX_Noise_Info_Diag_Raw_Value_Ptr
 *===========================================================================
 * RETURN VALUE:
 *    MMIC_Analog_Bist_Status_T * - Pointer to the first diagnostic entry in
 *                                  the RX Noise Info range [300, 307].
 * --------------------------------------------------------------------------
 * ABSTRACT: Returns a pointer to mmic_diag_values[300].
 * The caller iterates ptr[i].raw_value for i = 0 to 7 to access
 * all RX Noise Info raw values.
 * --------------------------------------------------------------------------
\*===========================================================================*/
MMIC_Analog_Bist_Status_T *Get_RX_Noise_Info_Diag_Raw_Value_Ptr(void)
{
   return &MMIC_Stream.MMIC_Data.mmic_diag_values[300U];
}

/*===========================================================================*\
 * FUNCTION: Get_IFVGA_Diag_Raw_Value_Ptr
 *===========================================================================
 * RETURN VALUE:
 *    MMIC_Analog_Bist_Status_T * - Pointer to the first diagnostic entry in
 *                                  the IFVGA range [326, 373].
 * --------------------------------------------------------------------------
 * ABSTRACT: Returns a pointer to mmic_diag_values[326].
 * The caller iterates ptr[i].raw_value for i = 0 to 47 to access
 * all IFVGA raw values for CAN population.
 * --------------------------------------------------------------------------
\*===========================================================================*/
MMIC_Analog_Bist_Status_T *Get_IFVGA_Diag_Raw_Value_Ptr(void)
{
   return &MMIC_Stream.MMIC_Data.mmic_diag_values[326U];
}

/*===========================================================================*\
 * FUNCTION: Get_Loopback_Diag_Raw_Value_Ptr
 *===========================================================================
 * RETURN VALUE:
 *    MMIC_Analog_Bist_Status_T * - Pointer to the first diagnostic entry in
 *                                  the Loopback range [398, 429].
 * --------------------------------------------------------------------------
 * ABSTRACT: Returns a pointer to mmic_diag_values[398].
 * The caller iterates ptr[i].raw_value for i = 0 to 31 to access
 * all Loopback raw values for CAN population.
 * --------------------------------------------------------------------------
\*===========================================================================*/
MMIC_Analog_Bist_Status_T *Get_Loopback_Diag_Raw_Value_Ptr(void)
{
   return &MMIC_Stream.MMIC_Data.mmic_diag_values[398U];
}

/*===========================================================================*\
 * FUNCTION: Update_Profiling_Time_Entry
 *===========================================================================
 * RETURN VALUE:
 *    void
 *

* PARAMETERS:
*    entry        - Pointer to profiling time entry structure to update
*    current_time - Current time measurement in milliseconds
*    first_time   - Flag indicating first measurement (true) or subsequent (false)
*
* --------------------------------------------------------------------------
* ABSTRACT:
* This function updates profiling time statistics for a given entry.
* On first call (first_time = true), it initializes the current, average,
* minimum, and maximum time values to the current time.
* On subsequent calls, it updates the running average (simple moving average
* of previous average and current time), and tracks the minimum and maximum
* times observed.
* --------------------------------------------------------------------------
*
\*===========================================================================*/
static void Update_Profiling_Time_Entry(volatile MMIC_Individual_Profiling_Times_T *entry, uint32_t current_time, bool first_time)
{
   entry->current_time = current_time;
   if (first_time)
   {
      entry->avg_time = current_time;
      entry->min_time = current_time;
      entry->max_time = current_time;
   }
   else
   {
      entry->avg_time = (entry->avg_time + current_time) / 2U;
      entry->min_time = MIN(entry->min_time, current_time);
      entry->max_time = MAX(entry->max_time, current_time);
   }
}

/*===========================================================================*\
 * FUNCTION: MARS_Copy_Bist_Result
 *===========================================================================
 * RETURN VALUE:
 * void
 *
 * PARAMETERS:
 * MMIC_Bist_Status_T       *dest - Destination BIST status structure to populate.
 * const mars_bist_result_t *src  - Source BIST result from the MARS API.
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Copies all fields from a mars_bist_result_t into an MMIC_Bist_Status_T.
 * Used for both the live mmic_bist_status and the debug mmic_bist_status_debug
 * copies inside RFE_Look_Complete.
 * --------------------------------------------------------------------------
\*===========================================================================*/
static void MARS_Copy_Bist_Result(MMIC_Bist_Status_T *dest, const mars_bist_result_t *src)
{
   uint8_t i;
   dest->safety_error_detected      = (uint8_t)src->safety_error_detected;
   dest->CORE_BANK_SFT_ERR_MON      = src->CORE_BANK_SFT_ERR_MON;
   dest->CORE_BANK_SFT_ERR_STATUS   = src->CORE_BANK_SFT_ERR_STATUS;
   dest->CORE_BANK_MCU_STS_MCU_MSSG = src->CORE_BANK_MCU_STS_MCU_MSSG;
   dest->CORE_BANK_SFT_STATUS       = src->CORE_BANK_SFT_STATUS;
   dest->ASYNC_BANK_ASYNC_ERR1      = src->ASYNC_BANK_ASYNC_ERR1;
   dest->CORE_BANK_ENA_ERR          = src->CORE_BANK_ENA_ERR;
   dest->CPLL_BANK_REFPLL_ERR       = src->CPLL_BANK_REFPLL_ERR;
   dest->CPU_SYS_DMA_ERR            = src->CPU_SYS_DMA_ERR;
   dest->CPU_SYS_MCU_ERR_0          = src->CPU_SYS_MCU_ERR_0;
   dest->CPU_SYS_MCU_ERR_1          = src->CPU_SYS_MCU_ERR_1;
   dest->CPU_SYS_MCU_ERR_2          = src->CPU_SYS_MCU_ERR_2;
   dest->LOGEN_BANK_CHRP_GEN_ERROR  = src->LOGEN_BANK_CHRP_GEN_ERROR;
   dest->LOGEN_BANK_LOGEN_ERROR     = src->LOGEN_BANK_LOGEN_ERROR;
   dest->MIPI_BANK_IRQ_STATUS       = src->MIPI_BANK_IRQ_STATUS;
   dest->PROF_BANK_PRF_ERR1         = src->PROF_BANK_PRF_ERR1;
   dest->PROF_BANK_PRF_ERR2         = src->PROF_BANK_PRF_ERR2;
   dest->RXADC_FUSAIRQV0            = src->RXADC_FUSAIRQV0;
   dest->RXADC_FUSAIRQV1            = src->RXADC_FUSAIRQV1;
   dest->CORE_BANK_FRM_ERR          = src->CORE_BANK_FRM_ERR;
   dest->RXADC_FUSAMON              = src->RXADC_FUSAMON;
   dest->maf_status                 = (uint8_t)src->maf_status;
   for (i = 0U; i < MARS_DIAG_VALUES_MAX_NUMBER_MAF_ERROR_STATUS; i++)
   {
      dest->mcu_diag_error_values[i] = src->mcu_diag_error_values[i];
   }
}

/*===========================================================================*\
 * FUNCTION: MARS_Look_Complete
 *===========================================================================
 * RETURN VALUE:
 * MMIC_Result_T - Success/failure of look completion flow.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Polls driver status, reads diagnostics and BIST results, updates MMIC
 * stream structures, handles safety/error logging, and records profiling
 * times for the look completion phase.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
MMIC_Result_T RFE_Look_Complete(void)
{
   static bool first_time_measurement_look_complete = true;
   uint32_t index_for_temp_diag;
   uint32_t index_for_diag_mmic;
   uint32_t time_cal_loop_wait           = 0U;
   uint32_t total_look_complete_time_cal = 0U;
   MMIC_Result_T ret_val                 = MMIC_SUCCESS;
   mars_bist_result_t mars_bist_result   = {0};
   // mars_gpio_level_en sft_err_chn_val                           = L0_IO_HI;
   mars_diag_t all_diag_values[MARS_DIAG_NUMBER_OF_ITEMS_APTIV] = {{0}};
   mars_diag_t temp_diag_values[TEMP_DIAG_READ_QUANTITY]        = {{0}};
   mars_driver_status_t mars_driver_status                      = MARS_BUSY;
   MMIC_Config_Status_T *mmic_cfg_status_ptr                    = &MMIC_Stream.MMIC_Data.mmic_config_status;

   bool api_fail = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   /* Capture start time for the entire look complete function */
   total_look_complete_time_cal = Measurement_debug_timer_ms;

   /*Polling for MARS_READ_WAIT_CYCLES * 1ms */
   time_cal_loop_wait              = Measurement_debug_timer_ms;
   MMIC_Profiling_Times.loop_count = 0;

   while ((MARS_BUSY == mars_driver_status) && (MMIC_Profiling_Times.loop_count < MARS_READ_WAIT_CYCLES))
   {
      (void)mars_read_driver_status(&Mars_Self_Layer2_InstanceDriver0, &mars_driver_status);
      MMIC_Profiling_Times.loop_count++;
   }

   Update_Profiling_Time_Entry(&MMIC_Profiling_Times.driver_status_poll_time, Measurement_debug_timer_ms - time_cal_loop_wait,
                               first_time_measurement_look_complete);

   if (MARS_BUSY != mars_driver_status)
   {
      API_Ret_Val = E_OK;
   }

   MMIC_Custom_RW_Request();

   if (!CW_MODE_FLAG)
   {
      /*Read all the diagnostic raw values*/
      if (E_OK == (API_Ret_Val & API_ONLY_ERROR_MASK))
      {
         API_Ret_Val = mars_read_diag_raw(&Mars_Self_Layer2_InstanceDriver0, 0u, MARS_DIAG_NUMBER_OF_ITEMS_APTIV, all_diag_values);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_diag_raw in look complete fail\n");

         if (!api_fail)
         {
            /* Copy all diagnostic values into MMIC stream buffer */
            for (index_for_diag_mmic = 0U; index_for_diag_mmic < MARS_DIAG_NUMBER_OF_ITEMS_APTIV; index_for_diag_mmic++)
            {
               MMIC_Stream.MMIC_Data.mmic_diag_values[index_for_diag_mmic].raw_value =
                  all_diag_values[index_for_diag_mmic].raw_value;
               MMIC_Stream.MMIC_Data.mmic_diag_values[index_for_diag_mmic].state = all_diag_values[index_for_diag_mmic].state;
            }

            /* Copy only the first TEMP_DIAG_READ_QUANTITY items into the temperature diagnostics buffer */
            for (index_for_temp_diag = 0U; index_for_temp_diag < TEMP_DIAG_READ_QUANTITY; index_for_temp_diag++)
            {
               temp_diag_values[index_for_temp_diag].raw_value = all_diag_values[index_for_temp_diag].raw_value;
               temp_diag_values[index_for_temp_diag].state     = all_diag_values[index_for_temp_diag].state;
            }
         }
      }

      if (E_OK == (API_Ret_Val & API_ONLY_ERROR_MASK))
      {
         /* Update current temperature status and MMIC temperature report */
         Populate_Mars_Temperatures(temp_diag_values);
         Get_MMIC_Temp_Report();
      }

      if (E_OK == (API_Ret_Val & API_ONLY_ERROR_MASK))
      {
         API_Ret_Val = mars_read_bist_result(&Mars_Self_Layer2_InstanceDriver0, &mars_bist_result);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_bist_result in look complete fail\n");
         if (!api_fail)
         {
            MARS_Copy_Bist_Result(&MMIC_Stream.MMIC_Data.mmic_bist_status, &mars_bist_result);
#ifdef MARS_RESET_TEST_DUE_TO_ERROR
            /* sft_flip_test takes only values 0/1/2; case 1 resets the flag, case 2 keeps it.
               Clearing bit-0 maps: 1→0 (reset) and 2→2 (keep), avoiding a nested branch. */
            if (0U != sft_flip_test)
            {
               sft_flip_test &= ~1U; /* case 1→0, case 2→2 */
               mars_bist_result.CORE_BANK_SFT_ERR_MON =
                  (mars_bist_result.CORE_BANK_SFT_ERR_MON & ~(0x3 << (1 * 2))) | (0x1 << (1 * 2));
            }
#endif
            // Update_MMIC_SFR_err_mon(mars_bist_result.CORE_BANK_SFT_ERR_MON);
            if (((mars_bist_result.CORE_BANK_SFT_ERR_MON >> 2) & 0x3) == 0x1)
            {
               MARS_Reset_Counters.PLL_Unlock_Set_Count++;
               API_Ret_Val = MARS_Log_Critical_Debug_Regs();
               Set_MMIC_Error_Reinit(REINIT_MARS_SAFETY_CRITICAL_FAULT);
            }
         }
      }

      if (E_OK == (API_Ret_Val & API_ONLY_ERROR_MASK))
      {
         API_Ret_Val = MARS_LOG_CRITICAL_REG();
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_LOG_CRITICAL_REG fail\n");
      }
      if (!api_fail)
      {
         API_Ret_Val = MARS_Log_Calibration_Regs();
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_Log_Calibration_Regs fail\n");
      }
      if (!api_fail)
      {
         mars_rdrstatus_t rdr_status = {0};
         API_Ret_Val                 = mars_read_status(&Mars_Self_Layer2_InstanceDriver0, &rdr_status);
         api_fail                    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_gpio_sft_read fail\n");
      }
      if (!api_fail)
      {
         switch (XCP_MMIC_FIT_Enable)
         {
            case XCP_MMIC_SFT_RECOVERABLE_ERROR_FIT_TEST:
            case XCP_MMIC_SFT_NON_RECOVERABLE_ERROR_FIT_TEST:
            case XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_CLOCK_FAULT_FIT_TEST:
            case XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_MCU_FAULT_FIT_TEST:
            case XCP_MMIC_SFT_NON_RECOVERABLE_SECONDARY_REGISTER_FAULT_FIT_TEST:
            case XCP_MMIC_TX_BIST_FIT_TEST:
            case XCP_MMIC_RX_BIST_FIT_TEST:
               MMIC_Fault_Injection(XCP_MMIC_FIT_Enable, Get_Radar_Look());
               break;
            default:
               break;
         }
         if (1U == MMIC_Stream.MMIC_Data.mmic_bist_status.safety_error_detected) // ERROR PRESENT
         {
            MARS_SFT_Errors_Mon();
         }
         else
         {
            /*do nothing*/
         }
      }
      api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "Mars_Look_Complete fail\n");

      ret_val = !api_fail;

      /*increments only when there is error */
      API_Look_Complete_Error += (uint8_t)api_fail;

      mmic_cfg_status_ptr->mars_look_complete_status = Get_Status_Based_On_Api_Fail(api_fail);

      API_Look_Complete_Error =
         (XCP_MMIC_API_LOOK_COMPLETE_FIT_TEST == XCP_MMIC_FIT_Enable) ? (API_Look_Complete_Error + 1U) : API_Look_Complete_Error;
   }
#ifdef MARS_RESET_MECHANISM_ENABLED
   #ifdef MARS_RESET_TEST_DUE_TO_ERROR
   /* complete_flip_test takes only values 0/1/2; both non-zero cases force MMIC_FAIL.
      Case 1 additionally resets the flag; clearing bit-0 maps: 1→0 (reset), 2→2 (keep). */
   if (0U != complete_flip_test)
   {
      ret_val = MMIC_FAIL;
      complete_flip_test &= ~1U; /* case 1→0, case 2→2 */
   }
   #endif
   if (MMIC_FAIL == ret_val)
   {
      MARS_Reset_Request = true;
      MARS_Reset_Counters.look_complete_fail_reset_counter++;
      MARS_Reset_Counters.look_complete_fail_reset_reason = API_Ret_Val;
      MMIC_Stream.MMIC_Data.mars_api_error_code           = API_Ret_Val;

      MMIC_Stream.MMIC_Data.mmic_bist_api_ret_val = mars_read_bist_result(&Mars_Self_Layer2_InstanceDriver0, &mars_bist_result);
      MARS_Copy_Bist_Result(&MMIC_Stream.MMIC_Data.mmic_bist_status_debug, &mars_bist_result);
   }
   API_Ret_Val = MARS_E_OK; /*This is to allow some debounce, proceeding or not decision is taken based on number of retries*/
#endif

   /* Capture total look complete time and update min/max/avg */
   Update_Profiling_Time_Entry(&MMIC_Profiling_Times.look_complete_time, Measurement_debug_timer_ms - total_look_complete_time_cal,
                               first_time_measurement_look_complete);
   first_time_measurement_look_complete = false;

   return (ret_val);
}

/*===========================================================================*\
 * FUNCTION: MARS_Log_Critical_Debug_Regs
 *===========================================================================*
 * RETURN VALUE:
 * static Mars_ReturnType - See implementation for logging outcome.
 *
 * PARAMETERS:
 * Refer to signature for parameter usage.
 * --------------------------------------------------------------------------
 * ABSTRACT: Auto-generated placeholder documenting critical debug logging.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static Mars_ReturnType MARS_Log_Critical_Debug_Regs(void)
{
   bool api_fail                  = Is_MMIC_Api_Fail(API_Ret_Val, __func__);
   Mars_Critical_Registers_T *ptr = &MMIC_Stream.MMIC_Data.Mars_Critical_Registers;
   if (!api_fail)
   {
      API_Ret_Val = Mars_Read_Register_Value(MARS_R_RXADC_FUSAIRQV, &ptr->Mars_R_Rxadc_Fusairqv, NULL, 0);
      API_Ret_Val |= Mars_Read_Register_Value(MARS_R_CPU_SYS_MCU_ERR_0, &ptr->Mars_R_Cpu_Sys_Mcu_Err_0, NULL, 0);
      API_Ret_Val |= Mars_Read_Register_Value(MARS_R_CPU_SYS_MCU_ERR_1, &ptr->Mars_R_Cpu_Sys_Mcu_Err_1, NULL, 0);
      API_Ret_Val |= Mars_Read_Register_Value(MARS_R_CPU_SYS_MCU_ERR_2, &ptr->Mars_R_Cpu_Sys_Mcu_Err_2, NULL, 0);
   }

   return API_Ret_Val;
}

#if defined(MARS_HW_REV_A0)
/*===========================================================================*\
 * FUNCTION: MARS_Log_Critical_Regs
 *===========================================================================*
 * RETURN VALUE:
 * static Mars_ReturnType - See implementation for logging outcome.
 *
 * PARAMETERS:
 * Refer to signature for parameter usage.
 * --------------------------------------------------------------------------
 * ABSTRACT: Reads critical CPLL and system registers into MMIC stream,
 * tracks failures, and reports any register read errors using DCS_X macro pattern.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static Mars_ReturnType MARS_Log_Critical_Regs(void)
{
   uint32_t index_critical_regs;
   Mars_ReturnType ret_val = E_OK;
   bool api_fail           = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   uint16_t i;
   uint32_t mars_critical_reg_list[] = {MARS_LOG_CRITICAL_REG_LIST(MARS_LOG_CRITICAL_REG_NAME)};
   uint32_t *mars_critical_reg_ptr[] = {MARS_LOG_CRITICAL_REG_LIST(MARS_LOG_CRITICAL_REG_ADDR)};

   /* Tracks critical register read failures */
   if (!api_fail)
   {
      for (i = 0; i < MARS_CRITICAL_REG_MAX; i++)
      {
         ret_val = Mars_Read_Register_Value(mars_critical_reg_list[i], mars_critical_reg_ptr[i], NULL, 0);
         if (ret_val != E_OK)
         {
            break;
         }
      }
   }
   return ret_val;
}
#endif

/*===========================================================================*\
 * FUNCTION: MARS_Log_Calibration_Regs
 *===========================================================================
 * RETURN VALUE:
 * Mars_ReturnType - Status of calibration register readout.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Reads calibration registers into the MMIC stream, tracks failures,
 * and reports any register read errors.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static Mars_ReturnType MARS_Log_Calibration_Regs(void)
{
   uint32_t index_calib_regs;
   Mars_ReturnType ret_val = E_OK;
   bool api_fail           = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   uint16_t i;
   uint32_t mars_cal_reg_list[] = {MARS_LOG_CAL_REG_LIST(MARS_LOG_CAL_REG_NAME)};
   uint32_t *mars_cal_reg_ptr[] = {MARS_LOG_CAL_REG_LIST(MARS_LOG_CAL_REG_ADDR)};
   /* Tracks up to 88 registers (81 needed for superset) */
   uint8_t failed_reg_mask[MARS_CALIBRATION_REGISTERS_FAILURE_ARRAY_SIZE] = {0};

   if (!api_fail)
   {
      for (i = 0; i < MMARS_CAL_LOG_REG_MAX; i++)
      {
         ret_val = Mars_Read_Register_Value(mars_cal_reg_list[i], mars_cal_reg_ptr[i], failed_reg_mask, i);
         if (ret_val != E_OK)
         {
            ret_val = E_NOT_OK;
            break;
         }
      }

      /* ===================================================================
       * COPY FAILED REG MASK AND CHECK FOR FAILURES
       * =================================================================== */
      /* Copy the failed register mask to the stream for diagnostics */
      for (index_calib_regs = 0; index_calib_regs < MARS_CALIBRATION_REGISTERS_FAILURE_ARRAY_SIZE; index_calib_regs++)
      {
         MMIC_Stream.MMIC_Data.Mars_Calibration_Registers.Mars_Calibration_Registers_Failed_Mask[index_calib_regs] =
            failed_reg_mask[index_calib_regs];
      }

      /* Check if any register reads failed */
      for (index_calib_regs = 0; index_calib_regs < MARS_CALIBRATION_REGISTERS_FAILURE_ARRAY_SIZE; index_calib_regs++)
      {
         if (failed_reg_mask[index_calib_regs] != 0)
         {
            Log_MMIC_Error("MARS_Log_Calibration_Regs: Register read failures detected\n");
            ret_val = E_NOT_OK;
            break;
         }
      }
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: MARS_Config_Write_Tables
 *===========================================================================
 * RETURN VALUE:
 * bool - Updated API failure state for profiler table write stage.
 *
 * PARAMETERS:
 * Refer to signature for parameter usage.
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Populates table-0 and table-1 raw buffers and writes both tables.
 * --------------------------------------------------------------------------
\*===========================================================================*/
static bool MARS_Config_Write_Tables(uint64_t Look_Id, uint16_t starting_table_0_ind, uint16_t starting_table_1_ind,
                                     uint32_t *time_cal_ptr)
{
   uint16_t ind;
   uint16_t write_table0_idx;
   uint16_t write_table1_idx;
   uint8_t tx_control[4] = {0};
   uint32_t tx_SMC_value;
   uint32_t packedNum;
   bool api_fail = false;

   for (ind = starting_table_0_ind; ind < starting_table_0_ind + TABLE_0_ENTRIES_PER_LOOK; ind++)
   {
      write_table0_idx = ind - starting_table_0_ind;

      /* Phase rotator calibration mode - consolidated configuration under single condition */
      if (MMIC_Phase_Rotator_Calib_Mode)
      {
         Configure_Phase_Rotator_Calib_Table_0(write_table0_idx, ind, tx_control);
      }
      else
      {
         /* Normal and ACQ_CW mode configuration */
         if (MMIC_APTIV_OP_MODE_ACQ_CW == MMIC_Aptiv_Operation_Mode)
         {
            Table_0_Raw[write_table0_idx].s.t0_0.Fs = mars_table_0_fs_smc[starting_table_0_ind];
         }
         else
         {
            Table_0_Raw[write_table0_idx].s.t0_0.Fs = mars_table_0_fs_smc[ind];
         }

         Table_0_Raw[write_table0_idx].s.t0_0.RxEnAntAB = mars_table_0_rx_en_ant_ab_smc[ind];
         Table_0_Raw[write_table0_idx].s.t0_1.Td        = mars_table_0_td_smc[ind];
         Table_0_Raw[write_table0_idx].s.t0_1.Ts        = mars_table_0_ts_smc[ind];

         tx_SMC_value = mars_table_0_tx_en_smc[ind];
         Assemble_Tx_Control(tx_SMC_value, aptiv_tx_override_smc, tx_control);
         packedNum                                 = Pack_Tx_Control(tx_control);
         Table_0_Raw[write_table0_idx].s.t0_1.TxEn = packedNum;

         Table_0_Raw[write_table0_idx].s.t0_2.ChirpMode = mars_table_0_chirp_mode_smc[ind];
         Table_0_Raw[write_table0_idx].s.t0_2.T1Ptr     = mars_table_0_t1_ptr_smc[ind];

         if (MMIC_APTIV_OP_MODE_ACQ_CW == MMIC_Aptiv_Operation_Mode)
         {
            Table_0_Raw[write_table0_idx].s.t0_2.TxPhase0 = mars_table_0_tx_phase_smc[starting_table_0_ind][0];
            Table_0_Raw[write_table0_idx].s.t0_2.TxPhase1 = mars_table_0_tx_phase_smc[starting_table_0_ind][1];
            Table_0_Raw[write_table0_idx].s.t0_2.TxPhase2 = mars_table_0_tx_phase_smc[starting_table_0_ind][2];
            Table_0_Raw[write_table0_idx].s.t0_3.TxPhase3 = mars_table_0_tx_phase_smc[starting_table_0_ind][3];
         }
         else
         {
            Table_0_Raw[write_table0_idx].s.t0_2.TxPhase0 = mars_table_0_tx_phase_smc[ind][0];
            Table_0_Raw[write_table0_idx].s.t0_2.TxPhase1 = mars_table_0_tx_phase_smc[ind][1];
            Table_0_Raw[write_table0_idx].s.t0_2.TxPhase2 = mars_table_0_tx_phase_smc[ind][2];
            Table_0_Raw[write_table0_idx].s.t0_3.TxPhase3 = mars_table_0_tx_phase_smc[ind][3];
         }
      }
   }

   *time_cal_ptr = Measurement_debug_timer_ms;
   API_Ret_Val   = mars_profiler_table_0_write_raw(&Mars_Self_Layer2_InstanceDriver0, mars_table_0_offset_smc[Look_Id],
                                                   sizeof(Table_0_Raw) / MARS_PROFILER_T0_ELEMENT_SIZE_BYTES, Table_0_Raw);

   api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "mars_table_0_write_raw failed\n");

   if (api_fail)
   {
      /* error if any already reported above */
   }
   else if (E_OK != (API_Ret_Val & SFT_ONLY_ERROR_MASK))
   {
      MARS_SFT_Error_Counter.mars_profiler_table_0_write_raw_sft_error++;
   }
   else
   {
      /* do nothing */
   }

   if (!api_fail)
   {
      for (ind = starting_table_1_ind; ind < starting_table_1_ind + TABLE_1_ENTRIES_PER_LOOK; ind++)
      {
         write_table1_idx = ind - starting_table_1_ind;
         if (MMIC_APTIV_OP_MODE_ACQ_CW == MMIC_Aptiv_Operation_Mode)
         {
            Table_1_Raw[write_table1_idx].s.t1_4.Slope = 0; /* mars_table_1_slope_smc[starting_table_1_ind]; */
         }
         else
         {
            Table_1_Raw[write_table1_idx].s.t1_4.Slope = mars_table_1_slope_smc[ind];
         }
         Table_1_Raw[write_table1_idx].s.t1_4.VC              = mars_table_1_vc_smc[ind];
         Table_1_Raw[write_table1_idx].s.t1_4.AsyncFIFOThresh = mars_table_1_async_fifo_thresh_smc[ind];
         Table_1_Raw[write_table1_idx].s.t1_4.Tr              = mars_table_1_tr_smc[ind];

         Table_1_Raw[write_table1_idx].s.t1_5.NumSamp = mars_table_1_num_samp_smc[ind];
         Table_1_Raw[write_table1_idx].s.t1_5.HPF1    = mars_table_1_hpf1_smc[ind];
         Table_1_Raw[write_table1_idx].s.t1_5.HPF2    = mars_table_1_hpf2_smc[ind];
         Table_1_Raw[write_table1_idx].s.t1_5.DEC     = mars_table_1_dec_smc[ind];
         Table_1_Raw[write_table1_idx].s.t1_5.Te      = mars_table_1_te_smc[ind];
      }
      API_Ret_Val = mars_profiler_table_1_write_raw(&Mars_Self_Layer2_InstanceDriver0, mars_table_1_offset_smc[Look_Id],
                                                    sizeof(Table_1_Raw) / MARS_PROFILER_T1_ELEMENT_SIZE_BYTES, Table_1_Raw);

      api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "mars_table_1_write_raw failed\n");
      if (api_fail)
      {
         /* error if any already reported above */
      }
      else if (E_OK != (API_Ret_Val & SFT_ONLY_ERROR_MASK))
      {
         MARS_SFT_Error_Counter.mars_profiler_table_1_write_raw_sft_error++;
      }
      else
      {
         /* do nothing */
      }
   }

   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: MARS_Config_Configure_Look_Settings
 *===========================================================================
 * RETURN VALUE:
 * bool - Updated API failure state for configure/apply stage.
 *
 * PARAMETERS:
 * Refer to signature for parameter usage.
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Builds MARS config structures, applies runtime configuration, handles
 * BIST/cal writes, bias filter writes, and profiling updates.
 * --------------------------------------------------------------------------
\*===========================================================================*/
static bool MARS_Config_Configure_Look_Settings(uint64_t Look_Id, uint16_t Frame_Counter, bool *first_time_measurement_api_ptr)
{
   uint32_t time_cal = 0U;
   bool api_fail     = false;

   mars_rx_config_t cfg_rx                        = {0};
   mars_tx_config_t cfg_tx                        = {0};
   mars_rfdist_mode_t cfg_rfdist_mode             = {0};
   mars_bias_noise_filter_t cfg_bias_noise_filter = {0};
   mars_mipi_config_t cfg_mipi                    = {0};
   mars_chirp_config_t cfg_chirp                  = {0};
   mars_chirp_mode_t cfg_chirp_mode               = {0};
   mars_gp_config_t cfg_gp_config;
   mars_frame_counter_t cfg_frame_counter;
   mars_fusa_fs_t cfg_fusa_fs;

   cfg_tx.tx_en_mode    = mars_cfg_tx_config_tx_en_mode_smc[Look_Id];
   cfg_tx.tx_power      = mars_cfg_tx_config_tx_power_smc[Look_Id];
   cfg_tx.tx_on_offset  = (mars_tx_on_offset_t)mars_cfg_tx_config_tx_on_offset_smc[Look_Id];
   cfg_tx.tx_off_offset = (mars_tx_off_offset_t)mars_cfg_tx_config_tx_off_offset_smc[Look_Id];
   cfg_tx.tx_seq_offset = (mars_tx_seq_offset_t)mars_cfg_tx_config_tx_seq_offset_smc[Look_Id];
   cfg_tx.tx_ph_mode    = (mars_tx_ph_mode_t)mars_cfg_tx_config_tx_ph_mode_smc[Look_Id];

   cfg_rx.rx_en_mode = (mars_rx_en_mode_t)mars_cfg_rx_config_rx_en_mode_smc[Look_Id];
   if (Mars_OTP_Version >= MARS_OTP_VERSION_V10)
   {
      cfg_rx.rx_ifvga_gain = (mars_rx_ifvga_gain_t)mars_cfg_rx_config_rx_ifvga_gain_smc[Look_Id];
   }
   else
   {
      cfg_rx.rx_ifvga_gain = 10U; // this changes are brought to fix ADC
   }
   cfg_rx.rx_mixer_gain   = (mars_rx_mixer_gain_t)mars_cfg_rx_config_rx_mixer_gain_smc[Look_Id];
   cfg_rx.rx_on_offset    = (mars_rx_on_offset_t)mars_cfg_rx_config_rx_on_offset_smc[Look_Id];
   cfg_rx.rx_off_offset   = (mars_rx_off_offset_t)mars_cfg_rx_config_rx_off_offset_smc[Look_Id];
   cfg_rx.rx_seq_offset   = (mars_rx_seq_offset_t)mars_cfg_rx_config_rx_seq_offset_smc[Look_Id];
   cfg_rx.rx_adc_mode     = (mars_rx_adc_mode_t)mars_cfg_rx_config_rx_adc_mode_smc[Look_Id];
   cfg_rx.rx_adc_samp_frq = (mars_rx_adc_samp_frq_t)mars_cfg_rx_config_rx_adc_samp_frq_smc[Look_Id];

   cfg_rfdist_mode = (mars_rfdist_mode_t)mars_cfg_rfdist_mode_smc[Look_Id];

   cfg_mipi.mipi_data_lanes = (mars_mipi_tx_lanes_t)mars_cfg_mipi_config_mipi_data_lanes_smc[Look_Id];
   cfg_mipi.mipi_data_rate  = (mars_mipi_bitrate_t)mars_cfg_mipi_config_mipi_data_rate_smc[Look_Id];
   cfg_mipi.metadata_enable = (mars_mipi_metadata_enable_t)mars_cfg_mipi_config_mipi_metadata_enable_smc[Look_Id];
   cfg_mipi.power_mode      = (mars_mipi_power_mode_t)mars_cfg_mipi_config_mipi_power_mode_smc[Look_Id];

   cfg_chirp.chirps_per_frame      = (uint16_t)mars_cfg_chirp_config_chirps_per_frame_smc[Look_Id];
   cfg_chirp.repeatable_chirps_num = (uint8_t)mars_cfg_chirp_config_repeatable_chirps_num_smc[Look_Id];
   cfg_chirp.t0_start_pointer      = (uint16_t)mars_cfg_chirp_config_t0_start_pointer_smc[Look_Id];
   cfg_chirp.t0_end_pointer        = (uint16_t)mars_cfg_chirp_config_t0_end_pointer_smc[Look_Id];
   cfg_chirp.t1_start_pointer      = mars_cfg_chirp_config_t1_start_pointer_smc[Look_Id];
   cfg_chirp_mode.profiler_mode    = mars_cfg_chirp_mode_profiler_mode_smc[Look_Id];
   cfg_chirp_mode.mimo_mode        = mars_cfg_chirp_mode_mimo_mode_smc[Look_Id];
   cfg_gp_config.gp0               = mars_cfg_gp0_config_smc[Look_Id];
   cfg_gp_config.gp1               = mars_cfg_gp1_config_smc[Look_Id];
   cfg_frame_counter               = Frame_Counter;

   cfg_rx.rx_ifvga_stage_1   = mars_cfg_rx_ifvga_stage_1_smc[Look_Id];
   cfg_rx.rx_hpf_prechg_mode = mars_cfg_rx_hpf_prechg_mode_smc[Look_Id];
   cfg_bias_noise_filter     = mars_cfg_bias_noise_filter_smc[Look_Id];

   cfg_fusa_fs = (mars_fusa_fs_t)mars_cfg_maf_fusa_fs_smc[Look_Id];

   time_cal = Measurement_debug_timer_ms;
   if (Is_MIPI_Config_First_Time)
   {
      API_Ret_Val = mars_configure(&Mars_Self_Layer2_InstanceDriver0, &cfg_tx, &cfg_rx, &cfg_rfdist_mode, &cfg_bias_noise_filter,
                                   &cfg_mipi, &cfg_chirp, &cfg_chirp_mode, &cfg_gp_config, &cfg_frame_counter,
                                   mars_cfg_diag_addresses_smc[Look_Id], &cfg_fusa_fs);
      Is_MIPI_Config_First_Time = false;
   }
   else
   {
      API_Ret_Val = mars_configure(&Mars_Self_Layer2_InstanceDriver0, &cfg_tx, &cfg_rx, &cfg_rfdist_mode, &cfg_bias_noise_filter,
                                   NULL_PTR, &cfg_chirp, &cfg_chirp_mode, &cfg_gp_config, &cfg_frame_counter,
                                   mars_cfg_diag_addresses_smc[Look_Id], &cfg_fusa_fs);
   }

   MMIC_Profiling_Times.api_config_time.current_time = Measurement_debug_timer_ms - time_cal;
   api_fail                                          = Is_MMIC_Api_Fail(API_Ret_Val, "mars_configure fail\n");

   if ((!api_fail) && (XCP_MMIC_SOURCE_LEVEL_BIST_CONFIG_FIT_TEST == XCP_MMIC_FIT_Enable))
   {
      XCP_MMIC_FIT_Enable = XCP_MMIC_NO_FIT_TEST;
      if (!flag_zhb_calibration_USC)
      {
         API_Ret_Val = mars_configure_bist(&Mars_Self_Layer2_InstanceDriver0, mars_no_ZH_bist_config_smc);
      }
      else
      {
         API_Ret_Val = mars_configure_bist(&Mars_Self_Layer2_InstanceDriver0, mars_bist_config_smc);
      }
      api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "mars_configure_bist fail\n");
   }

   if (!api_fail)
   {
      API_Ret_Val = mars_cal_ctrl_write(&Mars_Self_Layer2_InstanceDriver0, &Calibration_Data_Place_Holder);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_cal_ctrl_write fail\n");
   }

   if (!api_fail)
   {
      uint16_t i;
      uint8_t bias_total_fails = 0U;
      uint8_t ret              = 0U;

      uint32_t mars_bias_cfg_list[] = {MARS_BIAS_CFG_REG_LIST(MARS_BIAS_CFG_REG_NAME)};
      uint32_t mars_bias_cfg_val[]  = {MARS_BIAS_CFG_REG_LIST(MARS_BIAS_CFG_REG_VAL)};
      uint8_t *mars_bias_cfg_ptr[]  = {MARS_BIAS_CFG_REG_LIST(MARS_BIAS_CFG_REG_FAIL)};

      for (i = 0; i < MMARS_BIAS_CFG_REG_MAX; i++)
      {
         ret = Mars_Write_Register_Value(mars_bias_cfg_list[i], mars_bias_cfg_val[i]);
         *mars_bias_cfg_ptr[i] += ret;
         bias_total_fails += ret;
      }

      if (bias_total_fails > 0U)
      {
         Log_MMIC_Error("Bias filter configuration failed\n");
      }
   }

   if (*first_time_measurement_api_ptr)
   {
      MMIC_Profiling_Times.api_config_time.avg_time = MMIC_Profiling_Times.api_config_time.current_time;
      MMIC_Profiling_Times.api_config_time.min_time = MMIC_Profiling_Times.api_config_time.current_time;
      MMIC_Profiling_Times.api_config_time.max_time = MMIC_Profiling_Times.api_config_time.current_time;

      MMIC_Profiling_Times.table_write_total_time.avg_time = MMIC_Profiling_Times.table_write_total_time.current_time;
      MMIC_Profiling_Times.table_write_total_time.min_time = MMIC_Profiling_Times.table_write_total_time.current_time;
      MMIC_Profiling_Times.table_write_total_time.max_time = MMIC_Profiling_Times.table_write_total_time.current_time;

      if (!Is_Force_No_Verify_Tables)
      {
         MMIC_Profiling_Times.table_read_total_time.avg_time = MMIC_Profiling_Times.table_read_total_time.current_time;
         MMIC_Profiling_Times.table_read_total_time.min_time = MMIC_Profiling_Times.table_read_total_time.current_time;
         MMIC_Profiling_Times.table_read_total_time.max_time = MMIC_Profiling_Times.table_read_total_time.current_time;
      }

      *first_time_measurement_api_ptr = false;
   }
   else
   {
      MMIC_Profiling_Times.api_config_time.avg_time =
         (MMIC_Profiling_Times.api_config_time.avg_time + MMIC_Profiling_Times.api_config_time.current_time) / 2;
      MMIC_Profiling_Times.api_config_time.min_time =
         MIN(MMIC_Profiling_Times.api_config_time.min_time, MMIC_Profiling_Times.api_config_time.current_time);
      MMIC_Profiling_Times.api_config_time.max_time =
         MAX(MMIC_Profiling_Times.api_config_time.max_time, MMIC_Profiling_Times.api_config_time.current_time);

      MMIC_Profiling_Times.table_write_total_time.avg_time =
         (MMIC_Profiling_Times.table_write_total_time.avg_time + MMIC_Profiling_Times.table_write_total_time.current_time) / 2;
      MMIC_Profiling_Times.table_write_total_time.min_time =
         MIN(MMIC_Profiling_Times.table_write_total_time.min_time, MMIC_Profiling_Times.table_write_total_time.current_time);
      MMIC_Profiling_Times.table_write_total_time.max_time =
         MAX(MMIC_Profiling_Times.table_write_total_time.max_time, MMIC_Profiling_Times.table_write_total_time.current_time);

      if (!Is_Force_No_Verify_Tables)
      {
         MMIC_Profiling_Times.table_read_total_time.avg_time =
            (MMIC_Profiling_Times.table_read_total_time.avg_time + MMIC_Profiling_Times.table_read_total_time.current_time) / 2;
         MMIC_Profiling_Times.table_read_total_time.min_time =
            MIN(MMIC_Profiling_Times.table_read_total_time.min_time, MMIC_Profiling_Times.table_read_total_time.current_time);
         MMIC_Profiling_Times.table_read_total_time.max_time =
            MAX(MMIC_Profiling_Times.table_read_total_time.max_time, MMIC_Profiling_Times.table_read_total_time.current_time);
      }
   }

   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: MARS_Config
 *===========================================================================
 * RETURN VALUE:
 * Mars_ReturnType - Status of configuration and table programming.
 *
 * PARAMETERS:
 *    uint64_t Look_Id       - Look configuration index.
 *    uint16_t Frame_Counter - Frame counter value to program.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Programs profiler tables, verifies table writes when enabled, configures
 * MARS RX/TX/MIPI/chirp settings, and applies bias filter setup.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType MARS_Config(uint64_t Look_Id, uint16_t Frame_Counter)
{
   static bool first_time_measurement_api = true;
   uint32_t time_cal                      = 0;
   /*Please dont delete any comments in this function*/

   uint16_t starting_table_0_ind = Look_Id * TABLE_0_ENTRIES_PER_LOOK;
   uint16_t starting_table_1_ind = Look_Id * TABLE_1_ENTRIES_PER_LOOK;

   bool api_fail = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   if (!api_fail)
   {
      api_fail = MARS_Config_Write_Tables(Look_Id, starting_table_0_ind, starting_table_1_ind, &time_cal);
   }

   MMIC_Profiling_Times.table_write_total_time.current_time = Measurement_debug_timer_ms - time_cal;
   time_cal                                                 = Measurement_debug_timer_ms;

   if (!Is_Force_No_Verify_Tables)
   {
      if (!api_fail)
      {
         API_Ret_Val = mars_profiler_table_0_read_raw(&Mars_Self_Layer2_InstanceDriver0, 400, TABLE_0_ENTRIES_PER_LOOK,
                                                      &Table_0_Raw_Return[0]);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_profiler_table_0_read_raw fail\n");
      }
      if (!api_fail)
      {
         API_Ret_Val =
            mars_profiler_table_1_read_raw(&Mars_Self_Layer2_InstanceDriver0, 0, TABLE_1_ENTRIES_PER_LOOK, &Table_1_Raw_Return[0]);
         api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "mars_profiler_table_1_read_raw fail\n");
      }

      if (!api_fail)
      {
         MMIC_Stream.MMIC_Data.mmic_config_status.mars_verify_tbl0_status = (bitfield32_t)MARS_Compare_Tables(
            (uint32_t *)Table_0_Raw, (uint32_t *)Table_0_Raw_Return, (sizeof(Table_0_Raw) / (sizeof(uint32_t))));
      }

      if (!api_fail)
      {
         MMIC_Stream.MMIC_Data.mmic_config_status.mars_verify_tbl1_status = (bitfield32_t)MARS_Compare_Tables(
            (uint32_t *)Table_1_Raw, (uint32_t *)Table_1_Raw_Return, (sizeof(Table_1_Raw) / (sizeof(uint32_t))));
      }
   }

   MMIC_Profiling_Times.table_read_total_time.current_time = Measurement_debug_timer_ms - time_cal;

   if (!api_fail)
   {
      api_fail = MARS_Config_Configure_Look_Settings(Look_Id, Frame_Counter, &first_time_measurement_api);
   }

   if (E_OK != (API_Ret_Val & API_ONLY_ERROR_MASK))
   {
      Log_MMIC_Error("mars_configure fail\n");
      MMIC_Stream.MMIC_Data.mmic_config_status.mars_config_status = 0U;
   }
   else if (E_OK != (API_Ret_Val & SFT_ONLY_ERROR_MASK))
   {
      MARS_SFT_Error_Counter.mars_configure_sft_error++;
      MMIC_Stream.MMIC_Data.mmic_config_status.mars_config_status = 1U;
   }
   else
   {
      MMIC_Stream.MMIC_Data.mmic_config_status.mars_config_status = 1U;
   }

   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: RFE_Init
 *===========================================================================*
 * RETURN VALUE:
 * MMIC_Result_T - Success/failure of RFE initialization flow.
 *
 * PARAMETERS:
 * None -
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Initializes the RFE (Radar Front End) subsystem by performing MARS
 * initialization, logging static parameters, verifying MMIC ID, configuring
 * startup parameters, and ZHB initialization. Updates configuration and
 * initialization status flags based on the outcome of each step. Supports
 * MARS reset mechanism for handling initialization failures.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
MMIC_Result_T RFE_Init(void)
{
   MMIC_Result_T ret_val;
   MMIC_ID_Status_T *mmic_id_status_ptr      = Get_Mmic_Id_Ptr();
   MMIC_Config_Status_T *mmic_cfg_status_ptr = &MMIC_Stream.MMIC_Data.mmic_config_status;

   API_Ret_Val   = MARS_Initialization();
   bool api_fail = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   if (api_fail)
   {
      ret_val = MMIC_FAIL;
   }
   else
   {
      if (!flag_zhb_calibration_USC)
      {
         API_Ret_Val = mars_configure_bist(&Mars_Self_Layer2_InstanceDriver0, mars_no_ZH_bist_config_smc);
      }
      else
      {
         API_Ret_Val = mars_configure_bist(&Mars_Self_Layer2_InstanceDriver0, mars_bist_config_smc);
      }
      api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "mars_configure_bist fail\n");

      if (!api_fail)
      {
         API_Ret_Val = MARS_Log_Static_Parameters();
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_Log_Static_Parameters fail\n");
      }
      if (!api_fail)
      {
         /* verify the mmic id*/
         API_Ret_Val = Verify_Mmic_Id(mmic_id_status_ptr, USC_CHIP_ID_ADDRESS, MMIC_RF_ID, CHIP_ID_LEN);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "Verify_Mmic_Id fail\n");
      }

      if (!api_fail)
      {
         API_Ret_Val = MARS_Startup_Config();
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_Startup_Config fail\n");
      }
      if (!api_fail)
      {
         API_Ret_Val = MARS_ZHB_Initialization();
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_ZHB_Initialization fail\n");
      }

      ret_val                               = !api_fail;
      mmic_cfg_status_ptr->mars_init_status = Get_Status_Based_On_Api_Fail(api_fail);
   }
#ifdef MARS_RESET_MECHANISM_ENABLED
   #ifdef MARS_RESET_TEST_DUE_TO_ERROR
   if (1U == init_flip_test)
   {
      ret_val        = MMIC_FAIL;
      init_flip_test = 0U;
   }
   else if (2U == init_flip_test)
   {
      ret_val = MMIC_FAIL;
   }
   #endif
   if (MMIC_FAIL == ret_val)
   {
      MARS_Reset_Request = true;
      MARS_Reset_Counters.mars_init_fail_reset_counter++;
      MARS_Reset_Counters.mars_init_fail_reset_reason = API_Ret_Val;
      MMIC_Stream.MMIC_Data.mars_api_error_code       = API_Ret_Val;
   }
   API_Ret_Val = MARS_E_OK; /*This is to allow some debounce, proceeding or not decision is taken based on number of retries*/
#endif

   return (ret_val);
}

/*===========================================================================*\
 * FUNCTION: MMIC_Update_Profiling_Spec_Config_Time
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    MMIC_Individual_Profiling_Times_T *profiling_time_ptr - Profiling entry to update.
 *    bool *first_time_measurement_ptr                      - First-measurement flag.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Updates min/avg/max profiling stats for spec config timing, tracking
 * first-measurement initialization versus steady-state updates.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MMIC_Update_Profiling_Spec_Config_Time(volatile MMIC_Individual_Profiling_Times_T *profiling_time_ptr,
                                            bool *first_time_measurement_ptr)
{
   if (*first_time_measurement_ptr)
   {
      profiling_time_ptr->avg_time = profiling_time_ptr->current_time;
      profiling_time_ptr->min_time = profiling_time_ptr->current_time;
      profiling_time_ptr->max_time = profiling_time_ptr->current_time;
      *first_time_measurement_ptr  = false;
   }
   else
   {
      profiling_time_ptr->avg_time = (profiling_time_ptr->avg_time + profiling_time_ptr->current_time) >> BIT_1;
      profiling_time_ptr->min_time = MIN(profiling_time_ptr->min_time, profiling_time_ptr->current_time);
      profiling_time_ptr->max_time = MAX(profiling_time_ptr->max_time, profiling_time_ptr->current_time);
   }
}

/*===========================================================================*\
 * FUNCTION: compute_crc32
 *===========================================================================
 * RETURN VALUE:
 *    uint32_t - Computed CRC32 value.
 *
 * PARAMETERS:
 *    const uint32_t *data_words  - Pointer to array of 32-bit words to compute CRC over.
 *    size_t          num_words   - Number of 32-bit words in data_words.
 *    uint32_t        polynomial  - CRC32 generator polynomial.
 *    uint8_t         reflect_input  - Non-zero to process bytes in reflected (LSB-first) order.
 *    uint8_t         reflect_output - Non-zero to reflect the final CRC value before output.
 *    uint8_t         endianness  - 0 for little-endian byte order, non-zero for big-endian.
 *    uint32_t        crc_seed    - Initial CRC register value.
 *    uint8_t         use_xor     - Non-zero to XOR final CRC with final_xor; zero to XOR with crc_seed.
 *    uint32_t        final_xor   - Value XORed into the final CRC when use_xor is non-zero.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Computes a CRC32 checksum over an array of 32-bit words. Each word is
 * split into bytes according to the specified endianness, then processed
 * byte-by-byte using a pre-generated lookup table. Supports reflected and
 * normal (non-reflected) CRC variants, configurable seed, and optional
 * final XOR masking.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint32_t compute_crc32(const uint32_t *data_words, size_t num_words, uint32_t polynomial, uint8_t reflect_input,
                       uint8_t reflect_output, uint8_t endianness, uint32_t crc_seed, uint8_t use_xor, uint32_t final_xor)
{
   uint32_t table[256];
   uint32_t crc = crc_seed;

   generate_crc32_table(polynomial, reflect_input, table);

   for (size_t idx = 0; idx < num_words; idx++)
   {
      uint32_t word = data_words[idx];
      uint8_t bytes[4];

      /* Convert word to bytes based on endianness */
      if (endianness == 0)
      {
         /* Little Endian */
         bytes[0] = (uint8_t)(word & 0xFF);
         bytes[1] = (uint8_t)((word >> 8) & 0xFF);
         bytes[2] = (uint8_t)((word >> 16) & 0xFF);
         bytes[3] = (uint8_t)((word >> 24) & 0xFF);
      }
      else
      {
         /* Big Endian */
         bytes[0] = (uint8_t)((word >> 24) & 0xFF);
         bytes[1] = (uint8_t)((word >> 16) & 0xFF);
         bytes[2] = (uint8_t)((word >> 8) & 0xFF);
         bytes[3] = (uint8_t)(word & 0xFF);
      }

      /* Process each byte */
      for (int i = 0; i < 4; i++)
      {
         uint8_t b = bytes[i];
         uint32_t index;

         if (reflect_input)
         {
            index = (crc ^ b) & 0xFFU;
            crc   = (crc >> 8) ^ table[index];
         }
         else
         {
            index = ((crc >> 24) ^ b) & 0xFFU;
            crc   = (crc << 8) ^ table[index];
         }

         crc &= 0xFFFFFFFFU;
      }
   }

   /* Final XOR processing */
   if (use_xor)
   {
      crc ^= final_xor;
   }
   else
   {
      crc ^= crc_seed;
   }

   /* Reflect output if needed */
   if ((reflect_output ^ reflect_input) != 0U)
   {
      crc = reflect_bits(crc, 32);
   }

   return crc;
}
/*===========================================================================*\
 * FUNCTION: reflect_bits
 *===========================================================================
 * RETURN VALUE:
 *    uint32_t - The bit-reversed value of data within the specified width.
 *
 * PARAMETERS:
 *    uint32_t data  - Input value whose bits are to be reflected.
 *    uint8_t  width - Number of bits to reflect (e.g. 8 for a byte, 32 for a word).
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Reflects (reverses) the bit order of the input value within the given
 * bit width. Bit 0 maps to bit (width-1), bit 1 maps to bit (width-2),
 * and so on. Used by the CRC32 routines to support reflected polynomial
 * and reflected output modes.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint32_t reflect_bits(uint32_t data, uint8_t width)
{
   uint32_t reflect_result = 0U;

   for (uint8_t i = 0; i < width; i++)
   {
      if (data & (1UL << i))
      {
         reflect_result |= (1UL << ((width - 1U) - i));
      }
   }

   return reflect_result;
}
/*===========================================================================*\
 * FUNCTION: generate_crc32_table
 *===========================================================================
 * RETURN VALUE:
 *    void - Table is populated in-place via the output parameter.
 *
 * PARAMETERS:
 *    uint32_t  polynomial    - CRC32 generator polynomial.
 *    uint8_t   reflect_input - Non-zero to generate a reflected (LSB-first) table;
 *                              zero to generate a normal (MSB-first) table.
 *    uint32_t  table[256]    - Output array of 256 pre-computed CRC32 values,
 *                              one entry per possible byte value.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Pre-computes the 256-entry CRC32 lookup table for the given polynomial
 * and bit-reflection setting. When reflect_input is non-zero the polynomial
 * is itself reflected before table generation and reflected CRC shift logic
 * is applied; otherwise normal MSB-first shift logic is used. The resulting
 * table is consumed by compute_crc32 to process input data one byte at a time.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void generate_crc32_table(uint32_t polynomial, uint8_t reflect_input, uint32_t table[256])
{
   uint32_t poly;
   uint32_t crc;
   uint16_t byte;
   uint8_t j;

   if (reflect_input)
   {
      poly = reflect_bits(polynomial, 32);
   }
   else
   {
      poly = polynomial;
   }

   for (byte = 0; byte < 256; byte++)
   {
      crc = (uint32_t)byte;

      if (reflect_input)
      {
         /* Reflected CRC logic */
         for (j = 0; j < 8; j++)
         {
            if (crc & 0x00000001U)
            {
               crc = (crc >> 1) ^ poly;
            }
            else
            {
               crc >>= 1;
            }
         }
      }
      else
      {
         /* Normal CRC logic */
         crc <<= 24;

         for (j = 0; j < 8; j++)
         {
            if (crc & 0x80000000U)
            {
               crc = (crc << 1) ^ poly;
            }
            else
            {
               crc <<= 1;
            }

            crc &= 0xFFFFFFFFU;
         }
      }

      table[byte] = crc;
   }
}

/*===========================================================================*\
 * FUNCTION: ZHV_Data_Update_From_Raw_Diagnostics
 *===========================================================================
 * RETURN VALUE:
 * bool - Updated API failure state after RFBIST calibration handling.
 *
 * PARAMETERS:
 * bool api_fail - Incoming API failure state.
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Updates the ZHV data except a,b, theta from Raw Diagnostics array
 * --------------------------------------------------------------------------
\*===========================================================================*/
static void ZHV_Data_Update_From_Raw_Diagnostics(void)
{
   /* variables for Buffer to shuffle with Raw Diag Data*/
   uint16_t zhv_idx;
   uint16_t diag_pair_idx;
   uint16_t loopback_map_idx;
   uint32_t lower_12_bits = 0U;
   uint32_t upper_12_bits = 0U;
   uint32_t expectedCRC   = 0;
   /*Indexes of Loopback Phase 0 & 1: I & Q Data excluding a,b & theta*/
   static const uint16_t loopback_zhv_indices[] = {55U, 56U, 57U, 58U, 62U, 63U, 64U, 65U, 69U, 70U, 71U, 72U, 76U, 77U, 78U, 79U};
   /*PM_TX_PD mapping from the updated ZHV table. */
   static const uint16_t pm_tx_pd_zhv_indices[] = {87U, 88U, 89U, 90U};
   static const uint16_t pm_tx_pd_raw_indices[] = {198U, 199U, 200U, 201U};

   MMIC_Analog_Bist_Status_T *rf_inject_diag_ptr = Get_RF_Inject_RX_Diag_Raw_Value_Ptr();
   MMIC_Analog_Bist_Status_T *ifvga_diag_ptr     = Get_IFVGA_Diag_Raw_Value_Ptr();
   MMIC_Analog_Bist_Status_T *loopback_diag_ptr  = Get_Loopback_Diag_Raw_Value_Ptr();

   uint32_t polynomial        = 0x04C11DB7;
   bool reflect_input         = false;
   bool reflect_output        = false;
   uint8_t endianness         = 1; /* BigEndian */
   uint32_t crc_seed          = 0xFFFFFFFF;
   uint8_t use_xor            = 0;
   uint32_t final_xor         = 0xFFFFFFFF;
   uint32_t ZHV_Buffer_length = 0;

   memcpy((void *)Inter_ZHB_Data_Buffer, MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.zhv_data_array,
          sizeof(Inter_ZHB_Data_Buffer));
   /* Replace ZHV indices 7..22 from raw diagnostics 250..281 (packed as low12 | (high12 << 12)). */
   for (zhv_idx = 7U, diag_pair_idx = 0U; zhv_idx <= 22U; zhv_idx++, diag_pair_idx += 2U)
   {
      lower_12_bits                  = (uint32_t)(rf_inject_diag_ptr[diag_pair_idx].raw_value & 0x0FFFU);
      upper_12_bits                  = (uint32_t)(rf_inject_diag_ptr[diag_pair_idx + 1U].raw_value & 0x0FFFU);
      Inter_ZHB_Data_Buffer[zhv_idx] = lower_12_bits | (upper_12_bits << 12U);
   }

   /* Replace ZHV indices 27..50 from IFVGA raw diagnostics 326..373. */
   for (zhv_idx = 27U, diag_pair_idx = 0U; zhv_idx <= 50U; zhv_idx++, diag_pair_idx += 2U)
   {
      lower_12_bits                  = (uint32_t)(ifvga_diag_ptr[diag_pair_idx].raw_value & 0x0FFFU);
      upper_12_bits                  = (uint32_t)(ifvga_diag_ptr[diag_pair_idx + 1U].raw_value & 0x0FFFU);
      Inter_ZHB_Data_Buffer[zhv_idx] = lower_12_bits | (upper_12_bits << 12U);
   }

   /* Replace Loopback ZHV indices from Loopback raw diagnostics 398..429. */
   for (loopback_map_idx = 0U, diag_pair_idx = 0U; loopback_map_idx < NUM_ELEMS(loopback_zhv_indices);
        loopback_map_idx++, diag_pair_idx += 2U)
   {
      lower_12_bits = (uint32_t)(loopback_diag_ptr[diag_pair_idx].raw_value & 0x0FFFU);
      upper_12_bits = (uint32_t)(loopback_diag_ptr[diag_pair_idx + 1U].raw_value & 0x0FFFU);
      Inter_ZHB_Data_Buffer[loopback_zhv_indices[loopback_map_idx]] = lower_12_bits | (upper_12_bits << 12U);
   }

   /* Replace PM_TX_PD ZHV indices 87..90 from raw diagnostics 198..201. */
   for (loopback_map_idx = 0U; loopback_map_idx < NUM_ELEMS(pm_tx_pd_raw_indices); loopback_map_idx++)
   {
      Inter_ZHB_Data_Buffer[pm_tx_pd_zhv_indices[loopback_map_idx]] =
         (uint32_t)(MMIC_Stream.MMIC_Data.mmic_diag_values[pm_tx_pd_raw_indices[loopback_map_idx]].raw_value & 0x0FFFU);
   }

   /* Replace PVT index 95 from raw diagnostics*/
   Inter_ZHB_Data_Buffer[95U] = (uint32_t)((int32_t)MMIC_Stream.MMIC_Data.mmic_diag_values[1].raw_value -
                                           (int32_t)MMIC_Stream.MMIC_Data.mmic_diag_values[0].raw_value);

   Inter_ZHB_Data_Buffer[2] = 0x0;
   ZHV_Buffer_length        = Inter_ZHB_Data_Buffer[1];
   /*CRC_Calculation*/
   expectedCRC              = compute_crc32((const uint32_t *)Inter_ZHB_Data_Buffer, /* pointer to first element */
                                            ZHV_Buffer_length,                       /* number of 32-bit words */
                                            polynomial, reflect_input, reflect_output, endianness, crc_seed, use_xor, final_xor);
   Inter_ZHB_Data_Buffer[2] = expectedCRC;

   memcpy(MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.zhv_data_array, (const void *)Inter_ZHB_Data_Buffer,
          sizeof(Inter_ZHB_Data_Buffer));
   MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.Rfbist_Calibration_Status = RFBIST_CALIBRATION_SUCCESSFUL;
}

/*===========================================================================*\
 * FUNCTION: Rfe_Bist_Calibration_Trigger
 *===========================================================================
 * RETURN VALUE:
 * bool - Updated API failure state after RFBIST calibration handling.
 *
 * PARAMETERS:
 * bool api_fail - Incoming API failure state.
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Handles triggered RFBIST zero-hour calibration generation, write/readback,
 * and LUT comparison against USC data.
 * --------------------------------------------------------------------------
\*===========================================================================*/
static bool Rfe_Bist_Calibration_Trigger(void)
{
   bool api_fail = Is_MMIC_Api_Fail(API_Ret_Val, __func__);
   /*Need to Generate the ZHB as long as the Flash does not already have ZHB*/
   if ((!api_fail) && (MMIC_XCP_BIST_Calib_Trigger))
   {
      MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.Rfbist_Calibration_Status = RFBIST_CALIBRATION_IN_PROGRESS;
      API_Ret_Val =
         mars_zhv_generate(&Mars_Self_Layer2_InstanceDriver0, MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.zhv_data_array, 100);
      api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "ZHB Generation failed\n");

      MMIC_XCP_BIST_Calib_Trigger = false;
      if (!api_fail)
      {
         ZHV_Data_Update_From_Raw_Diagnostics();
      }
      else
      {
         MMIC_Stream.MMIC_Data.RFBIST_Zero_Hr_Ref_Data.Rfbist_Calibration_Status = (uint8_t)RFBIST_CALIBRATION_FAILED;
      }
   }

   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: RFE_Look_Configure_Normal_Path
 *===========================================================================
 * RETURN VALUE:
 * bool - Updated API failure state for non-CW path.
 *
 * PARAMETERS:
 * Refer to signature for parameter usage.
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Handles normal-path look configure flow including test-pattern transitions,
 * LUT reload, look config update, CW exit reconfigure, and BIST calibration trigger.
 * --------------------------------------------------------------------------
\*===========================================================================*/
static bool RFE_Look_Configure_Normal_Path(volatile MMIC_Config_Status_T *mmic_cfg_status_ptr,
                                           volatile MMIC_Individual_Profiling_Times_T *mmic_profiling_spec_config_ptr,
                                           bool *first_time_measurement_ptr)
{
   bool api_fail               = false;
   uint32_t rxadc_ovld_reg_val = 0U;
   uint32_t time_cal;
   uint8_t look_id;

   if (!Is_CW_Mode_Enabled)
   {
      bool test_pattern_requested = (MMIC_APTIV_OP_MODE_TEST_PATTERN == MMIC_Aptiv_Operation_Mode);
      if (test_pattern_requested != Is_Test_Pattern_Enabled)
      {
         if (test_pattern_requested)
         {
            API_Ret_Val                                         = MARS_Start_Test_Pattern_Mode();
            api_fail                                            = Is_MMIC_Api_Fail(API_Ret_Val, "Start Test Pattern mode fail\n");
            mmic_cfg_status_ptr->mars_start_test_pattern_status = Get_Status_Based_On_Api_Fail(api_fail);
         }
         else
         {
            API_Ret_Val                                        = MARS_Stop_Test_Pattern_Mode();
            api_fail                                           = Is_MMIC_Api_Fail(API_Ret_Val, "Stop Test Pattern mode fail\n");
            mmic_cfg_status_ptr->mars_stop_test_pattern_status = Get_Status_Based_On_Api_Fail(api_fail);
         }

         if (!api_fail)
         {
            Is_Test_Pattern_Enabled = test_pattern_requested;
         }
      }

      if (Is_Force_TX_Phase_LUT_Reload)
      {
         API_Ret_Val = MARS_Startup_Config();
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "LUT Reload failed\n");
         if (!api_fail)
         {
            Is_Force_TX_Phase_LUT_Reload = false;
         }
      }

      API_Ret_Val = mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_R_RXADC_OVLD, &rxadc_ovld_reg_val);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_R_RXADC_OVLD read fail\n");

      if (!api_fail)
      {
         rxadc_ovld_reg_val |= 0x1U; /* Set bit 0: MARS_F_RXADC_OVLD_BYP */
         API_Ret_Val = mars_write_register(&Mars_Self_Layer2_InstanceDriver0, MARS_R_RXADC_OVLD, rxadc_ovld_reg_val);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_R_RXADC_OVLD write fail\n");
      }

      if ((!api_fail) && ((aptiv_allow_updates_smc) || (0U == Frame_Counter)))
      {
         look_id                                      = (uint8_t)Get_Radar_Look();
         time_cal                                     = Measurement_debug_timer_ms;
         API_Ret_Val                                  = MARS_Config(look_id, Frame_Counter);
         mmic_profiling_spec_config_ptr->current_time = Measurement_debug_timer_ms - time_cal;

         MMIC_Update_Profiling_Spec_Config_Time(mmic_profiling_spec_config_ptr, first_time_measurement_ptr);
         api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "config in norm mode fail\n");
      }
   }
   else
   {
      API_Ret_Val = MARS_Stop_CW_Mode();
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "Stop CW mode fail\n");
      if (!api_fail)
      {
         Is_CW_Mode_Enabled = false;
         look_id            = (uint8_t)Get_Radar_Look();
         API_Ret_Val        = MARS_Config(look_id, Frame_Counter);
         api_fail           = Is_MMIC_Api_Fail(API_Ret_Val, "config in CW mode fail\n");

         mmic_cfg_status_ptr->mars_start_cw_mode_status = Get_Status_Based_On_Api_Fail(api_fail);
      }
   }
   if (!api_fail)
   {
      api_fail = Rfe_Bist_Calibration_Trigger();
   }

   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: RFE_Look_Configure_CW_Path
 *===========================================================================
 * RETURN VALUE:
 * bool - Updated API failure state for CW path.
 *
 * PARAMETERS:
 * mars_diag_t diag_values_for_temp[TEMP_DIAG_READ_QUANTITY] - Buffer for temp diagnostics.
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Handles CW-path look configure flow, including CW entry and runtime
 * diagnostic/temperature updates.
 * --------------------------------------------------------------------------
\*===========================================================================*/
static bool RFE_Look_Configure_CW_Path(mars_diag_t diag_values_for_temp[TEMP_DIAG_READ_QUANTITY])
{
   bool api_fail = false;

   if (!Is_CW_Mode_Enabled)
   {
      API_Ret_Val = MARS_Start_CW_Mode();
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "Start CW mode fail\n");
      if (!api_fail)
      {
         Is_CW_Mode_Enabled = true;
      }
   }

   if (Is_CW_Mode_Enabled)
   {
      API_Ret_Val = mars_update_diagnostic_values(&Mars_Self_Layer2_InstanceDriver0);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_update_diagnostic_values failed\n");
      if (!api_fail)
      {
         API_Ret_Val = mars_read_diag_raw(&Mars_Self_Layer2_InstanceDriver0, 0u, TEMP_DIAG_READ_QUANTITY, diag_values_for_temp);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_diag_raw fail in cw mode mars config\n");
         if (!api_fail)
         {
            Populate_Mars_Temperatures(diag_values_for_temp);
         }
      }
   }

   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: MARS_Look_Config
 *===========================================================================
 * RETURN VALUE:
 * MMIC_Result_T - Success/failure of the look configuration flow.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Manages normal/CW/test-pattern look configuration, updates profiling
 * timing metrics, and maintains look config status and fault counters.
 * --------------------------------------------------------------------------
\*===========================================================================*/
MMIC_Result_T RFE_Look_Configure(void)
{
   static bool first_time_measurement = true;
   MMIC_Result_T ret_val              = MMIC_SUCCESS;
   MMIC_Aptiv_Operation_Mode          = aptiv_operation_mode_smc;

   volatile MMIC_Individual_Profiling_Times_T *mmic_profiling_spec_config_ptr = &MMIC_Profiling_Times.spec_config_time;
   volatile MMIC_Config_Status_T *mmic_cfg_status_ptr                         = &MMIC_Stream.MMIC_Data.mmic_config_status;
   mars_diag_t diag_values_for_temp[TEMP_DIAG_READ_QUANTITY];

   bool api_fail = Is_MMIC_Api_Fail(API_Ret_Val, __func__);
   if (!api_fail)
   {
      /* Reset the status for every cycle */
      mmic_cfg_status_ptr->mars_look_complete_status = 0U;
      mmic_cfg_status_ptr->mars_look_trigger_status  = 0U;
      mmic_cfg_status_ptr->mars_look_config_status   = 0U;

      if (!CW_MODE_FLAG)
      {
         API_Ret_Val =
            RFE_Look_Configure_Normal_Path(mmic_cfg_status_ptr, mmic_profiling_spec_config_ptr, &first_time_measurement);
         api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "RFE_Look_Configure_Normal_Path failed\n");
      }
      else
      {
         API_Ret_Val = RFE_Look_Configure_CW_Path(diag_values_for_temp);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "RFE_Look_Configure_CW_Path failed\n");
      }
      Frame_Counter++;
   }
   if (E_OK != (API_Ret_Val & API_ONLY_ERROR_MASK))
   {
      ret_val                                      = MMIC_FAIL;
      mmic_cfg_status_ptr->mars_look_config_status = 0U;
      API_Look_Config_Error++;
   }
   else
   {
      mmic_cfg_status_ptr->mars_look_config_status = 1U;
      API_Look_Config_Error                        = 0U;
   }
#ifdef MARS_RESET_MECHANISM_ENABLED
   #ifdef MARS_RESET_TEST_DUE_TO_ERROR
   if (1U == config_flip_test)
   {
      ret_val          = MMIC_FAIL;
      config_flip_test = 0U;
   }
   else if (2U == config_flip_test)
   {
      ret_val = MMIC_FAIL;
   }
   else
   {
      /*Do nothing*/
   }
   #endif
   if (MMIC_FAIL == ret_val)
   {
      MARS_Reset_Request = true;
      MARS_Reset_Counters.look_config_fail_reset_counter++;
      MARS_Reset_Counters.look_config_fail_reset_reason = API_Ret_Val;
      MMIC_Stream.MMIC_Data.mars_api_error_code         = API_Ret_Val;
   }
// API_Ret_Val = MARS_E_OK; /*This is to allow some debounce, proceeding or not decision is taken based on number of retries*/
#endif
   return (ret_val);
}

/*===========================================================================*\
 * FUNCTION: RFE_Look_Trigger
 *===========================================================================
 * RETURN VALUE:
 * MMIC_Result_T - Success/failure of the look trigger flow.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Clears recoverable SFT errors, updates status, triggers the frame, and
 * updates profiling metrics and fault counters for the look trigger stage.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
MMIC_Result_T RFE_Trigger(void)
{
   static bool first_time_measurement_look_trigger = true;
   MMIC_Result_T ret_val                           = MMIC_SUCCESS;
   mars_rdrstatus_t rdr_status                     = {0};
   uint32_t total_look_trigger_time_cal            = Measurement_debug_timer_ms;

   bool api_fail = Is_MMIC_Api_Fail(API_Ret_Val, __func__);

   Update_Mars_Reg_From_OTP(); /* Update MARS register from OTP before every look trigger as per Gen8 requirement */

   if (!CW_MODE_FLAG)
   {
      mars_write_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_LOGEN_BANK_CHRP_GEN_RST_SLOPE, mars_chrp_gen_rst_slope_smc);
      if (!api_fail)
      {
         /*Enable this if need to see the pattern of triggers*/
         /*param_counter[Get_Radar_Look()]++;
         if (seq_index < SEQ_LOG_SIZE)
         {
            param_sequence[seq_index] = Get_Radar_Look();
            seq_index++;
         }*/
         API_Ret_Val = mars_clear_recoverable_sft_errors(&Mars_Self_Layer2_InstanceDriver0);
         if (Is_Test_Pattern_Enabled)
         {
            API_Ret_Val = MARS_Start_Test_Pattern_Mode();
            api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "Start Test Pattern mode fail inside trigger\n");
         }
         if (!api_fail)
         {
            API_Ret_Val = mars_read_status(&Mars_Self_Layer2_InstanceDriver0, &rdr_status);
            api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_status fail\n");
            if (!api_fail)
            {
               MMIC_Stream.MMIC_Data.current_sys_status.sft_error   = rdr_status.sft_error;
               MMIC_Stream.MMIC_Data.current_sys_status.mcu_status  = rdr_status.mcu_status;
               MMIC_Stream.MMIC_Data.current_sys_status.ctrl_status = (uint8_t)rdr_status.ctrl_status;
            }
         }

         Mars_Register_Write_Custom();

         if (true == Read_Write_Enable)
         {
            uint32_t read_back_value = 0U;
            if (!api_fail && Mars_Write_Register_Config.register_address != 0U)
            {
               API_Ret_Val = Mars_Write_Register_Value(Mars_Write_Register_Config.register_address,
                                                       Mars_Write_Register_Config.register_value);
               api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_write_register fail\n");

               if (!api_fail)
               {
                  API_Ret_Val = mars_read_register(&Mars_Self_Layer2_InstanceDriver0, Mars_Write_Register_Config.register_address,
                                                   &read_back_value);
                  api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_register fail\n");
               }

               if (!api_fail && (read_back_value == Mars_Write_Register_Config.register_value))
               {
                  Mars_Write_Register_Config.data_confirm = true;
               }
            }

            if (!api_fail && Mars_Read_Register_Config.register_address != 0U)
            {
               API_Ret_Val = Mars_Read_Register_Value(Mars_Read_Register_Config.register_address, &read_back_value, NULL, 0);
               Mars_Read_Register_Config.register_value = read_back_value;
               api_fail                                 = Is_MMIC_Api_Fail(API_Ret_Val, "mars_read_register fail\n");
               if (!api_fail)
               {
                  Mars_Read_Register_Config.data_confirm = true;
               }
            }
            Read_Write_Enable = false;
         }
         API_Ret_Val = mars_trigger_frame(&Mars_Self_Layer2_InstanceDriver0, 0, 0);
         // MARS_GET_ERROR_INFORMATION_INDIVIDUAL_VALUE(API_Ret_Val, Mars_Api_Id, Mars_Error_Type, Mars_Error_Id);
         api_fail = Is_MMIC_Api_Fail(API_Ret_Val, "Mars_Look_Trigger fail\n");

         if (api_fail)
         {
            ret_val = MMIC_FAIL;
            API_Look_Trigger_Error++;

            MMIC_Stream.MMIC_Data.mmic_config_status.mars_look_trigger_status = 0U;
         }
         else
         {
            MMIC_Stream.MMIC_Data.mmic_config_status.mars_look_trigger_status = 1U;

            if (E_OK != (API_Ret_Val & SFT_ONLY_ERROR_MASK))
            {
               MARS_SFT_Error_Counter.mars_trigger_frame_sft_error++;
            }
            else
            {
               if (XCP_MMIC_API_LOOK_TRIGGER_FIT_TEST == XCP_MMIC_FIT_Enable)
               {
                  API_Look_Trigger_Error++;
               }
               else
               {
                  API_Look_Trigger_Error = 0U;
               }
            }

            if (!Is_Triggered_Once)
            {
               Is_Triggered_Once = true;
            }
         }
      }
   }
#ifdef MARS_RESET_MECHANISM_ENABLED
   #ifdef MARS_RESET_TEST_DUE_TO_ERROR
   if (1U == trigger_flip_test)
   {
      ret_val           = MMIC_FAIL;
      trigger_flip_test = 0U;
   }
   else if (2U == trigger_flip_test)
   {
      ret_val = MMIC_FAIL;
   }
   #endif
   if (MMIC_FAIL == ret_val)
   {
      MARS_Reset_Request = true;
      MARS_Reset_Counters.look_trigger_fail_reset_counter++;
      MARS_Reset_Counters.look_trigger_fail_reset_reason = API_Ret_Val;
      MMIC_Stream.MMIC_Data.mars_api_error_code          = API_Ret_Val;
   }
   API_Ret_Val = MARS_E_OK; /*This is to allow some debounce, proceeding or not decision is taken based on number of retries*/
#endif

   Update_Profiling_Time_Entry(&MMIC_Profiling_Times.look_trigger_time, Measurement_debug_timer_ms - total_look_trigger_time_cal,
                               first_time_measurement_look_trigger);
   first_time_measurement_look_trigger = false;

   return (ret_val);
}

/*===========================================================================*\
 * FUNCTION: Get_Tx_Id_Fault
 *===========================================================================
 * RETURN VALUE:
 * CODED_TRUE / CODED_FALSE based on the mismatch count value
 *
 * PARAMETERS:
 *    uint8_t
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Returns CODED_TRUE : mismatch count is non zero(Tx Id Fault is SET),
 *         CODED_FALSE : mismatch count is zero(no Tx Id Fault)
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t Get_Tx_Id_Fault(void)
{
   MMIC_ID_Status_T *mmic_id_status_ptr = Get_Mmic_Id_Ptr();

   return ((RETRY_COUNT <= mmic_id_status_ptr->mmic_id_mismatch_cnt) ? CODED_TRUE : CODED_FALSE);
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Unprogrammed_Fault
 *===========================================================================
 * RETURN VALUE:
 *    ret_val
 *    CODED_TRUE - MMIC Unprogrammed
 *    CODED_FALSE - MMIC Programmed
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: return status if MMIC chip is programmed (USC) or not
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t Get_MMIC_Unprogrammed_Fault(void)
{
   uint8_t ret_val;
   MMIC_ID_Status_T *mmic_id_status_ptr = Get_Mmic_Id_Ptr();

   ret_val = (CODED_FALSE != mmic_id_status_ptr->mmic_id_programmed) ? CODED_FALSE : CODED_TRUE;

   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: Get_Mmic_Id_Ptr
 *===========================================================================
 * RETURN VALUE:
 *    &MMIC_Stream.MMIC_Data.MMIC_Fault_Status.mmic_id_status
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Returns adddress of mmic_id_status
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
MMIC_ID_Status_T *Get_Mmic_Id_Ptr(void)
{
   return (&MMIC_Stream.MMIC_Data.mmic_id_status);
}

#ifdef MARS_RESET_MECHANISM_ENABLED
/*===========================================================================*\
 * FUNCTION: MARS_Reset
 *===========================================================================
 * RETURN VALUE:
 *   uint8_t
 *  Success - true, Failure - false
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: This function resets Mars if at all any failure in normal mode
 * of operation is detected.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
MMIC_Result_T MARS_Reset(void)
{
   MMIC_Result_T ret_val = MMIC_SUCCESS;
   bool api_fail;
   MARS_Reset_Counters.total_reset_counter++;
   if (MMIC_RFE_INIT_UPLOAD_ONLY_WITH_RESET_RETRY == MMIC_RFE_Init_State)
   {
      MMIC_RFE_Init_State = MMIC_RFE_INIT_UPLOAD_ONLY_WITH_RESET_RETRY;
   }
   else
   {
      MMIC_RFE_Init_State = MMIC_RFE_INIT_UPLOAD_THEN_ACTIVATE;
   }

   API_Ret_Val = mars_reset(&Mars_Self_Layer2_InstanceDriver0, MARS_RESET_HARD);
   api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_reset fail\n");

   if (!api_fail)
   {
      // MARS_GET_ERROR_INFORMATION_INDIVIDUAL_VALUE(API_Ret_Val, Mars_Api_Id, Mars_Error_Type, Mars_Error_Id);
      MARS_Reset_Request = false;
      ret_val            = MMIC_SUCCESS;
   }
   else
   {
      ret_val = MMIC_FAIL;
   }

   return ret_val;
}
#endif

/*===========================================================================*\
 * FUNCTION: Get_Chip_Id_Information_Ptr
 *===========================================================================
 * RETURN VALUE:
 *    Pointer to the first two fields (si_name_version and uid) of Mars_UID
 * PARAMETERS:
 *    void
 * ABSTRACT:
 * Returns pointer to the first two fields of Mars_UID as a byte pointer.
 * Use CHIP_ID_LEN for the length (see macro definition).
 *===========================================================================*/
mars_si_name_version_t *Get_Chip_Id_Information_Ptr(void)
{
   return (&Mars_UID.si_name_version);
}

/*===========================================================================*\
 * FUNCTION: Mars_Register_Write_MetaData_Packet_Type
 *===========================================================================*
 * RETURN VALUE:
 * Mars_ReturnType - Status of metadata packet type register write operation.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Writes the MARS ASYNC_BANK_ASYNC_META_DATA_TYPE register to configure
 * the metadata packet format. Sets the register to 0x2A (Raw8 format) as
 * the default metadata type for MIPI transmission.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType Mars_Register_Write_MetaData_Packet_Type(void)
{
   mars_reg_id_t regId;
   mars_reg_value_t regVal;
   regId  = MARS_F_ASYNC_BANK_ASYNC_META_DATA_TYPE;
   regVal = 0x2A; // Raw8 value -> this is the default

   API_Ret_Val = mars_write_register(&Mars_Self_Layer2_InstanceDriver0, regId, regVal);
   (void)Is_MMIC_Api_Fail(API_Ret_Val, "MARS_F_ASYNC_BANK_ASYNC_META_DATA_TYPE write fail\n");

   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: Mars_Register_Write_Custom
 *===========================================================================
 * RETURN VALUE:
 * bool - Returns true if any API call failed, false if all calls succeeded.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT: Performs custom register writes for MIPI async data type and
 * optional continuous HS clock configuration based on RDI log connection
 * status. Updates API failure status and logs any errors via UART.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool Mars_Register_Write_Custom(void)
{
   mars_reg_id_t regId;
   mars_reg_value_t regVal;
   regId  = MARS_F_ASYNC_BANK_ASYNC_DATA_TYPE;
   regVal = 0x2D;
   bool api_fail;

   API_Ret_Val = mars_write_register(&Mars_Self_Layer2_InstanceDriver0, regId, regVal);
   api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_F_ASYNC_BANK_ASYNC_DATA_TYPE write fail\n");

   if (Check_RDI_Log_Connection())
   {
      regId  = MARS_F_MIPI_BANK_CFG_CONTINUOUS_HS_CLK;
      regVal = 1;

      API_Ret_Val = mars_write_register(&Mars_Self_Layer2_InstanceDriver0, regId, regVal);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_F_MIPI_BANK_CFG_CONTINUOUS_HS_CLK write fail\n");
   }

   return api_fail;
}

/*===========================================================================*\
 * FUNCTION: Mars_Register_Write_Custom_Post_Activation
 *===========================================================================
 * RETURN VALUE:
 * Mars_ReturnType - Status of the post-activation register writes.
 *
 * PARAMETERS:
 * None -
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Performs post-activation custom register writes for the LOGEN synth
 * charge pump currents and reports any failures through the MMIC error
 * logging helper.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
Mars_ReturnType Mars_Register_Write_Custom_Post_Activation(void)
{
   mars_reg_id_t regId;
   mars_reg_value_t regVal;
   bool api_fail;
   /*
      uint32_t mars_post_act_list[] = {MARS_F_LOGEN_BANK_SYNTH_CP1_CUR, MARS_F_LOGEN_BANK_SYNTH_CP2_CUR};
      uint32_t mars_post_act_val[] = {0x02U, 0x06U};

      uint8_t i;

      for(i=0U; i<NUM_ELEMS(mars_post_act_list); i++)
      {
        ret = Mars_Write_Register_Value(mars_post_act_list[i], mars_post_act_val[i]);
        if(ret != 0U)
        {
          break;
        }
      }
   */
   regId  = MARS_F_LOGEN_BANK_SYNTH_CP1_CUR;
   regVal = 0x2;
   // MARS_GET_ERROR_INFORMATION_INDIVIDUAL_VALUE(API_Ret_Val, Mars_Api_Id, Mars_Error_Type, Mars_Error_Id);
   API_Ret_Val = mars_write_register(&Mars_Self_Layer2_InstanceDriver0, regId, regVal);
   api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_F_LOGEN_BANK_SYNTH_CP1_CUR write fail\n");

   if (!api_fail)
   {
      regId  = MARS_F_LOGEN_BANK_SYNTH_CP2_CUR;
      regVal = 0x6;

      // MARS_GET_ERROR_INFORMATION_INDIVIDUAL_VALUE(API_Ret_Val, Mars_Api_Id, Mars_Error_Type, Mars_Error_Id);
      API_Ret_Val = mars_write_register(&Mars_Self_Layer2_InstanceDriver0, regId, regVal);
      api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "MARS_F_LOGEN_BANK_SYNTH_CP2_CUR write fail\n");
   }

   return API_Ret_Val;
}

/*===========================================================================*\
 * FUNCTION: mm_intf0_handler_worker
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Worker hook for MMIC interface 0 handler to query the SFT status and
 * acknowledge the action in the MMIC driver layer.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void mm_intf0_handler_worker(void)
{
   // (void)mars_action_sft_is_active(&Mars_Self_Layer2_InstanceDriver0);
}

/*===========================================================================*\
 * FUNCTION: Populate_MMIC_Stream
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: Populate the MMIC stream
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Populate_MMIC_Stream(void)
{
   SH_Output_T *sh_output_data_ptr = Get_SH_Output_Data_Ptr();
   MMIC_Stream_T *stream_ptr;
   stream_ptr                                = &MMIC_Stream;
   stream_ptr->sensor_dwell_time_sec         = Radar_Data_Status.radar_data_status_payload.end_dwell_sec;
   stream_ptr->sensor_dwell_time_ns          = Radar_Data_Status.radar_data_status_payload.end_dwell_nanosec;
   stream_ptr->sensor_mid_dwell_time_ns      = Radar_Data_Status.radar_data_status_payload.mid_dwell_nanosec;
   stream_ptr->sensor_mid_dwell_time_sec     = Radar_Data_Status.radar_data_status_payload.mid_dwell_sec;
   stream_ptr->sensor_dwell_time_duration_ns = Sensor_Dwell_Time_Duration_Ns;
   stream_ptr->look_type                     = (uint16_t)Get_Radar_Look();
   stream_ptr->scan_index                    = Get_Radar_Scan_Index();
   stream_ptr->stream_hdr.scan_index         = Get_Radar_Scan_Index();

   memcpy(stream_ptr->MMIC_Data.RFBIST_Zero_Hr_Ref_Data.active_bist_config, mars_bist_config_smc,
          sizeof(stream_ptr->MMIC_Data.RFBIST_Zero_Hr_Ref_Data.active_bist_config));

   /* Low temperature Fault into mmic stream */
   stream_ptr->MMIC_Data.temperature_fault.low_temperature_fault = Get_MMIC_Low_Temperature_Fault();

   /* Calculate checksum */
   /*Calculate_Checksum((uint8_t *)stream_ptr, sizeof(MMIC_Stream_T));*/ // CSH, Commented out temporarily

   (void)sh_output_data_ptr->sh_trigger_stream_handler_fptr(MMIC, (uint8_t *)stream_ptr);
}

/*===========================================================================*\
 * FUNCTION: MMIC_Custom_RW_Request
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Executes a pending custom MMIC register or memory block read/write request
 * and stores the result back into the corresponding request structure.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void MMIC_Custom_RW_Request(void)
{
   if (MMIC_Custom_Reg_RW.access_type == MMIC_RW_CUSTOM_ACCESS_READ)
   {
      MMIC_Custom_Reg_RW.access_type   = MMIC_RW_CUSTOM_ACCESS_INVALID;
      MMIC_Custom_Reg_RW.reg_value     = 0;
      MMIC_Custom_Reg_RW.return_status = 0xFF;
      MMIC_Custom_Reg_RW.return_status =
         mars_read_register(&Mars_Self_Layer2_InstanceDriver0, (mars_reg_id_t const)MMIC_Custom_Reg_RW.reg_address,
                            (mars_reg_value_t *)&MMIC_Custom_Reg_RW.reg_value);
   }

   if (MMIC_Custom_Reg_RW.access_type == MMIC_RW_CUSTOM_ACCESS_WRITE)
   {
      MMIC_Custom_Reg_RW.access_type   = MMIC_RW_CUSTOM_ACCESS_INVALID;
      MMIC_Custom_Reg_RW.return_status = 0xFF;
      MMIC_Custom_Reg_RW.return_status =
         mars_write_register(&Mars_Self_Layer2_InstanceDriver0, (mars_reg_id_t const)MMIC_Custom_Reg_RW.reg_address,
                             (mars_reg_value_t)MMIC_Custom_Reg_RW.reg_value);
   }

   if (MMIC_Custom_Memblk_RW.access_type == MMIC_RW_CUSTOM_ACCESS_READ)
   {
      MMIC_Custom_Memblk_RW.access_type   = MMIC_RW_CUSTOM_ACCESS_INVALID;
      MMIC_Custom_Memblk_RW.memblk_value  = 0;
      MMIC_Custom_Memblk_RW.return_status = 0xFF;
      MMIC_Custom_Memblk_RW.return_status =
         mars_read_memory(&Mars_Self_Layer2_InstanceDriver0, MMIC_Custom_Memblk_RW.memblk_address,
                          (mars_value_t *const)&MMIC_Custom_Memblk_RW.memblk_value, (mars_size_t)(4U / sizeof(mars_value_t)));
   }

   if (MMIC_Custom_Memblk_RW.access_type == MMIC_RW_CUSTOM_ACCESS_WRITE)
   {
      MMIC_Custom_Memblk_RW.access_type   = MMIC_RW_CUSTOM_ACCESS_INVALID;
      MMIC_Custom_Memblk_RW.return_status = 0xFF;
      MMIC_Custom_Memblk_RW.return_status = mars_write_memory(
         &Mars_Self_Layer2_InstanceDriver0, MMIC_Custom_Memblk_RW.memblk_address,
         (const mars_value_t *const)&MMIC_Custom_Memblk_RW.memblk_value, (mars_size_t)(4U / sizeof(mars_value_t)));
   }
}

/*===========================================================================*\
 * FUNCTION: Clear_And_Copy
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    char *dest        - Destination buffer to clear and fill.
 *    size_t dest_size  - Size of destination buffer in bytes.
 *    const char *src   - Source string to copy into destination.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Clears the destination buffer and copies the source string into it.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Clear_And_Copy(char *dest, size_t dest_size, const char *src)
{
   memset(dest, 0, dest_size);
   strncpy(dest, src, dest_size - 1);
   dest[dest_size - 1] = '\0';
}

/*===========================================================================*\
 * FUNCTION: Assemble_Tx_Control
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    uint32_t smc_value  - Raw SMC TX enable bitfield.
 *    uint8_t *tx_override - Per-channel override mode array.
 *    uint8_t *tx_control  - Output per-channel enable values.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Builds the per-channel TX control array from the SMC bitfield and
 * override settings.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Assemble_Tx_Control(uint32_t smc_value, uint8_t *tx_override, uint8_t *tx_control)
{
   uint8_t i;

   for (i = 0; i < 4; i++)
   {
      switch (tx_override[i])
      {
         case 0: // Keep the SMC Value
            tx_control[i] = GET_BIT(smc_value, i);
            break;
         case 1: // Override the SMC value and turn the port on
            tx_control[i] = 1;
            break;
         case 2: // Override the SMC value and turn the port off
            tx_control[i] = 0;
            break;
         default:
            return;
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Pack_Tx_Control
 *===========================================================================
 * RETURN VALUE:
 *    uint32_t - Packed TX enable bitfield.
 *
 * PARAMETERS:
 *    uint8_t *tx_control - Per-channel TX enable values.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Packs the per-channel TX control array into a 4-bit value.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint32_t Pack_Tx_Control(uint8_t *tx_control)
{
   uint32_t packedNum = 0U;
   uint8_t i;

   for (i = 0U; i < 4U; i++)
   {
      packedNum |= (tx_control[i] << i);
   }
   return packedNum;
}

/*===========================================================================*\
 * FUNCTION: Verify_Mmic_Id
 *===========================================================================
 * RETURN VALUE:
 *   int32_t
 *  Success - 0 , Failure - Error Code
 *
 * PARAMETERS:
 * MMIC_ID_Status_T *mmic_id_status_ptr,
 * const uint8_t *usc_mmic_id_ptr,
 * const uint8_t *mmic_id_ptr,
 * const uint8_t id_len
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: This function performs the following checks
 * 1. Compares the Rf Die ID with USC Chip Id related to Rf Die ID in USC
 * and will return the mismatch counter,if Rf Die ID(from Indie API mars_read_uid) not
 * matched with USC Chip ID inside the USC.
 * 2. This function will return ZERO Error code if the Rf Die ID(from Indie API mars_read_uid)
 * matches with the Chip ID fields(related to Rf Die ID) Present in The USC.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
int32_t Verify_Mmic_Id(MMIC_ID_Status_T *mmic_id_status_ptr, const uint8_t *usc_mmic_id_ptr, const uint8_t *mmic_id_ptr,
                       const uint8_t id_len)
{
   uint8_t chip_id_usc = 0U;
   uint8_t i;
   uint8_t mmic_tx_id_valid = 0U;
   int32_t ret_val          = E_OK;

   /* chip id and rf die id comaprison */
   for (i = 0U; i < id_len; i++)
   {
      /* chip id usc check, 0: not programmed, non zero: programmed */
      chip_id_usc |= usc_mmic_id_ptr[i];

      /* chip and rf die id comparison, 0: matched, non zero: not matched */
      mmic_tx_id_valid |= (uint8_t)(usc_mmic_id_ptr[i] - mmic_id_ptr[i]);
   }
   /* check whether usc programmed or not */
   if (chip_id_usc > 0U)
   {
      /* usc programmed */
      mmic_id_status_ptr->mmic_id_programmed = CODED_TRUE;

      if (mmic_tx_id_valid > 0U)
      {
         /* increment the counter */
         mmic_id_status_ptr->mmic_id_mismatch_cnt++;

         /* report error */
         ret_val = E_NOT_OK;
      }
      else
      {
         /* reset the counter */
         mmic_id_status_ptr->mmic_id_mismatch_cnt = 0U;

         /* no error */
         ret_val = E_OK;
      }
   }
   else
   {
      /* usc not programmed */
      mmic_id_status_ptr->mmic_id_programmed = CODED_FALSE;
   }

   return ret_val;
}

/*===========================================================================*\
* FUNCTION: Update_Usc_Mmic_Id
*===========================================================================
* RETURN VALUE:
* void
*
*
* PARAMETERS:
* const uint8_t *usc_mmic_id_ptr,
* const uint8_t *mmic_id_ptr,
* const uint8_t id_len
*
* --------------------------------------------------------------------------
* ABSTRACT: This function copy the rf die id data into usc chip id fields
* based on the fit method, loaded rf die id data exactly into usc chip
* id fields for positive fit method, loaded wrong rf die id data into
* usc chip id fields for negative fit method
*
* --------------------------------------------------------------------------
*
\*===========================================================================*/
void Update_Usc_Mmic_Id(uint8_t *usc_mmic_id_ptr, const uint8_t *mmic_id_ptr, const uint8_t id_len)
{
   uint8_t i;

   /* load the rf die id data into ucs chip id */
   for (i = 0U; i < id_len; i++)
   {
      if (XCP_MMIC_ID_FIT_POS_TEST == XCP_MMIC_FIT_Enable)
      {
         usc_mmic_id_ptr[i] = mmic_id_ptr[i];
      }
      else if (XCP_MMIC_ID_FIT_NEG_TEST == XCP_MMIC_FIT_Enable)
      {
         usc_mmic_id_ptr[i] = mmic_id_ptr[id_len - 1 - i];
      }
      else
      {
         /* do nothing */
      }
   }
}

/*===========================================================================*\
 * FUNCTION: Update_Usc_Mmic_Id
 *===========================================================================*
 * RETURN VALUE:
 * void - No return value.
 *
 * PARAMETERS:
 * uint8_t *usc_mmic_id_ptr       - Pointer to USC chip ID buffer to be updated.
 * const uint8_t *mmic_id_ptr     - Pointer to MMIC RF die ID data to copy from.
 * uint8_t id_len                 - Length of the ID data in bytes.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Copies MMIC RF die ID data into USC chip ID fields based on the fault
 * injection (FIT) method. For positive FIT, loads RF die ID data exactly
 * into USC chip ID fields. For negative FIT, loads reversed RF die ID data
 * (mirrored order) into USC chip ID fields.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static bool MARS_Compare_Tables(uint32_t *a1, uint32_t *a2, const uint32_t size)
{
   uint32_t idx;
   bool ret_val = true;

   for (idx = 0; idx < size; idx++)
   {
      if (a1[idx] != a2[idx])
      {
         ret_val = false;
      }
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: MARS_Metadata_Read
 *===========================================================================
 * RETURN VALUE:
 * void - No return value.
 *
 * PARAMETERS:
 * None
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Reads metadata from the MIPI FIFO and populates the MMIC stream with
 * metadata packet information including frame counter, radar status,
 * timestamp, and diagnostic data. Extracts individual bytes for CRC
 * calculation in reverse order per 32-bit value.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MARS_Metadata_Read(void)
{
   uint32_t fifo_status, index, index_byte;
   uint32 *pmeta_data_read = (uint32 *)(&Mars_Meta_Data_Read);
   uint32 meta_data_fifo_val;

   index_byte  = 0;
   fifo_status = ptrMIPI->CSR_META_FIFO_STATUS;

   /* Read all the meta data */
   for (index = 0; index < fifo_status; index++)
   {
      meta_data_fifo_val = ptrMIPI->CSR_META_READ_DATA;

      /* Store 32-bit values read in structure of type mars_meta_data_t */
      pmeta_data_read[index] = meta_data_fifo_val;

      /* Store data also as bytes for CRC calculation. Data CRC is calculated with data in reverse order per 32-bit value in mars
       */
      Meta_Data_Bytes[index_byte++] = UINT32_BYTE3(meta_data_fifo_val);
      Meta_Data_Bytes[index_byte++] = UINT32_BYTE2(meta_data_fifo_val);
      Meta_Data_Bytes[index_byte++] = UINT32_BYTE1(meta_data_fifo_val);
      Meta_Data_Bytes[index_byte++] = UINT32_BYTE0(meta_data_fifo_val);
   }

   // populate the meta data information on the mmic stream
   MMIC_Stream.MMIC_Data.MMIC_Meta_Data_Packet_Info.frame_counter      = Mars_Meta_Data_Read.frame_counter;
   MMIC_Stream.MMIC_Data.MMIC_Meta_Data_Packet_Info.meta_data_register = Mars_Meta_Data_Read.meta_data_register;
   MMIC_Stream.MMIC_Data.MMIC_Meta_Data_Packet_Info.radar_status       = Mars_Meta_Data_Read.radar_status;
   MMIC_Stream.MMIC_Data.MMIC_Meta_Data_Packet_Info.startup_time       = Mars_Meta_Data_Read.startup_time;
   MMIC_Stream.MMIC_Data.MMIC_Meta_Data_Packet_Info.timestamp_lsb      = UINT64_TO_LOWER32(Mars_Meta_Data_Read.timestamp);
   MMIC_Stream.MMIC_Data.MMIC_Meta_Data_Packet_Info.timestamp_msb      = UINT64_TO_UPPER32(Mars_Meta_Data_Read.timestamp);
   MMIC_Stream.MMIC_Data.MMIC_Meta_Data_Packet_Info.crc                = Mars_Meta_Data_Read.crc;

   memcpy(&MMIC_Stream.MMIC_Data.MMIC_Meta_Data_Packet_Info.reserved, Mars_Meta_Data_Read.reserved,
          (sizeof(uint32_t) * MARS_META_DATA_RESERVE_ARRAY));
   memcpy(&MMIC_Stream.MMIC_Data.MMIC_Meta_Data_Packet_Info.diag_data, Mars_Meta_Data_Read.diag_data,
          (sizeof(MARS_Meta_Data_Diag_T) * MARS_META_DATA_DIAG_ARRAY_SIZE));
}

/*===========================================================================*\
 * FUNCTION: MIPI_FuSa_Fault_Processing
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function process the MIPI FuSa faults and update the corresponding status flag.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void MIPI_FuSa_Fault_Processing(void)
{
   uint32_t irq0_mon_faults;
   uint32_t irq1_mon_faults;
   uint32_t irq2_mon_faults;
   MIPI_FuSa_IRQ_Fault_Info_T *mipi_fusa_irq_ptr = &MMIC_Stream.MMIC_Data.MIPI_FuSa_fault_info;
   /* Keep only enabled/monitored FuSa fault bits from each IRQ status register. */
   irq0_mon_faults = MIPI_FuSa_IRQ0_Mon_Status.register_value & MIPI_FUSA_IRQ0_ENABLE_MASK;
   irq1_mon_faults = MIPI_FuSa_IRQ1_Mon_Status.register_value & MIPI_FUSA_IRQ1_ENABLE_MASK;
   irq2_mon_faults = MIPI_FuSa_IRQ2_Mon_Status.register_value & MIPI_FUSA_IRQ2_ENABLE_MASK;

   /* check if any enabled FuSa fault bit is present across IRQ0/IRQ1/IRQ2. */
   if (0U != (irq0_mon_faults | irq1_mon_faults | irq2_mon_faults))
   {
      mipi_fusa_irq_ptr->mipi_csi2_data_err_cnt++;
      Set_MMIC_Error_Discard(DISCARD_ERROR_MIPI_RECOVERABLE_FAULT);
      /* copying into mmic stream */
      mipi_fusa_irq_ptr->mipi_fusa_irq0_reg = irq0_mon_faults;
      mipi_fusa_irq_ptr->mipi_fusa_irq1_reg = irq1_mon_faults;
      mipi_fusa_irq_ptr->mipi_fusa_irq2_reg = irq2_mon_faults;
      /* clear once after copy into stream */
      MIPI_FuSa_IRQ0_Mon_Status.register_value = 0x0U;
      MIPI_FuSa_IRQ1_Mon_Status.register_value = 0x0U;
      MIPI_FuSa_IRQ2_Mon_Status.register_value = 0x0U;
      /* Reaction Mechanism Once the error counter reached threshold*/
      if (MIPI_CSI2_DATA_ERR_THRESHOLD <= mipi_fusa_irq_ptr->mipi_csi2_data_err_cnt)
      {
         mipi_fusa_irq_ptr->mipi_data_fault        = CODED_TRUE;
         mipi_fusa_irq_ptr->mipi_csi2_data_err_cnt = 0U;
         Set_MMIC_Error_Reinit(REINIT_ERROR_MIPI_CSI2_FuSa_FAULT);
      }
   }
   else
   {
      mipi_fusa_irq_ptr->mipi_csi2_data_err_cnt = 0U;
      mipi_fusa_irq_ptr->mipi_data_fault        = CODED_FALSE;
   }
}

/*===========================================================================*\
 * FUNCTION: Get_MARS_Temp_Report
 *===========================================================================
 *===========================================================================
 * RETURN VALUE:
 * starting address of MMIC_Temperature.temperature_data
 *
 * PARAMETERS:
 * void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Returns starting address of MMIC_Temperature.temperature_data
 * --------------------------------------------------------------------------
 * Requirements:
 * PDD:
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
volatile MARS_Temparature_Data_T *Get_MARS_Temp_Report(void)
{
   return (&(MMIC_Temperature.temperature_data));
}

/*===========================================================================*\
 * FUNCTION: Get_MMIC_Stream_Ptr
 *===========================================================================*
 * RETURN VALUE:
 * MMIC_Stream_T * - Pointer to the MMIC stream structure.
 *
 * PARAMETERS:
 * void - No parameters.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Returns a pointer to the MMIC_Stream global structure containing all
 * MMIC-related data including configuration status, diagnostic values,
 * temperature readings, and fault information.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
MMIC_Stream_T *Get_MMIC_Stream_Ptr(void)
{
   return (&(MMIC_Stream));
}

/*===========================================================================*\
 * FUNCTION: Populate_Mars_Temperatures
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    mars_diag_t diag_values[TEMP_DIAG_READ_QUANTITY] - Array of diagnostic values containing raw temperature readings
 *                                                       and state information for all temperature sensors.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Updates the current temperature status in the MMIC stream from MARS
 * diagnostic values. Converts raw temperature readings to degrees Celsius
 * and updates state information for all 8 temperature sensors (PVT, PVT_TSENSE,
 * TX0-TX3, RX_TSENSE_GEN, QUAD_TSENSE_GEN). When not in CW mode, invalidates
 * RX and QUAD temperature readings by setting their values to zero and state
 * to MARS_VAL_BAD.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Populate_Mars_Temperatures(mars_diag_t diag_values[TEMP_DIAG_READ_QUANTITY])
{
   uint8_t idx;
   MMIC_Temperature_Status_T *current_temp_status_ptr = &(MMIC_Stream.MMIC_Data.current_temp_status);
   Mars_Temp_Update_T temp_update_var[]               = {
      {TEMP_IDX_PVT, &current_temp_status_ptr->state_pvt, &current_temp_status_ptr->temperature_pvt},
      {TEMP_IDX_PVT_TSENSE, &current_temp_status_ptr->state_pvt_tsense, &current_temp_status_ptr->temperature_pvt_tsense},
      {TEMP_IDX_PA0, &current_temp_status_ptr->state_tx0, &current_temp_status_ptr->temperature_tx0},
      {TEMP_IDX_PA1, &current_temp_status_ptr->state_tx1, &current_temp_status_ptr->temperature_tx1},
      {TEMP_IDX_PA2, &current_temp_status_ptr->state_tx2, &current_temp_status_ptr->temperature_tx2},
      {TEMP_IDX_PA3, &current_temp_status_ptr->state_tx3, &current_temp_status_ptr->temperature_tx3},
      {TEMP_IDX_RX_TSENSE_GEN, &current_temp_status_ptr->state_rx_tsense_gen, &current_temp_status_ptr->temperature_rx_tsense_gen},
      {TEMP_IDX_QUAD_TSENSE_GEN, &current_temp_status_ptr->state_quad_tsense_gen,
       &current_temp_status_ptr->temperature_quad_tsense_gen},
   };
   const uint8_t temp_update_count = (uint8_t)(sizeof(temp_update_var) / sizeof(temp_update_var[0]));

   /* Determine starting index based on CW mode */
   uint8_t temp_read_start_idx = Is_CW_Mode_Enabled ? TEMPERATURE_READ_DIAGS_NORMAL_MODE : MMIC_VAL_ZERO;

   /* If not in CW mode, invalidate RX/QUAD temperature readings (indices 6 and 7) */
   if (!Is_CW_Mode_Enabled)
   {
      diag_values[TEMP_IDX_RX_TSENSE_GEN].raw_value   = MMIC_VAL_ZERO;
      diag_values[TEMP_IDX_RX_TSENSE_GEN].state       = MARS_VAL_BAD;
      diag_values[TEMP_IDX_QUAD_TSENSE_GEN].raw_value = MMIC_VAL_ZERO;
      diag_values[TEMP_IDX_QUAD_TSENSE_GEN].state     = MARS_VAL_BAD;
   }

   for (idx = 0U; idx < temp_update_count; idx++)
   {
      const mars_diag_t *diag           = &diag_values[temp_read_start_idx + temp_update_var[idx].temp_idx];
      *temp_update_var[idx].state       = (uint8_t)diag->state;
      *temp_update_var[idx].temperature = MARS_RAW_TO_TEMP_DEGC(diag->raw_value);
   }
}

/*===========================================================================*\
 * FUNCTION: MARS_SFT_Errors_Mon
 *===========================================================================*
 * RETURN VALUE:
 * static void - No return value.
 *
 * PARAMETERS:
 * Refer to signature for parameter usage.
 * --------------------------------------------------------------------------
 * ABSTRACT: Auto-generated placeholder documenting SFT error monitoring hook.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void MARS_SFT_Errors_Mon(void)
{
   if (MAF_RECOVERABLE_FAULT == MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG)
   {
      Set_MMIC_Error_Discard(DISCARD_ERROR_RECOVERABLE_FAULT);
      Sensor_Dead_Fault_Error_Count++; // FOR SENSOR_DEAD_FAULT
   }
   else
   {
      Sensor_Dead_Fault_Error_Count = 0U; // FOR SENSOR DEAD FAULT
   }
   if (MAF_NON_RECOVERABLE_FAULT == MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG)
   {
      MARS_Reset_Counters.bist_non_recoverable_fault_count++;
      Set_MMIC_Error_Reinit(REINIT_MARS_NON_RECOVERABLE_FAULT); // Mars Reset request
   }
   Update_FSM_Mars_Errors();
}
/*===========================================================================*\
 * FUNCTION: Update_FSM_Mars_Errors
 *===========================================================================*
 * RETURN VALUE:
 * static void - No return value.
 *
 * PARAMETERS:
 * Refer to signature for parameter usage.
 * --------------------------------------------------------------------------
 * ABSTRACT: This function updates the FSM with the current Mars errors.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static void Update_FSM_Mars_Errors(void)
{
   /* Removed: Pre-loading 8 RXADC MOD registers - now loaded on-demand below */
   (void)memset((void *)&MMIC_Fusa_Active_Fault, 0, sizeof(MMIC_Fusa_Active_Fault));
   RFE_SFT_Err_Mon_Union_T sft_reg;
   sft_reg.register_value = MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_MON;

#ifdef UNIT_TEST

   uint8_t sft_reg_arr[17] = {sft_reg.bit_field.bor_power_error,
                              sft_reg.bit_field.reference_pll_lock,
                              sft_reg.bit_field.mcu_error,
                              sft_reg.bit_field.synthesizer_error,
                              sft_reg.bit_field.rx_adc,
                              sft_reg.bit_field.frame_unit_error,
                              sft_reg.bit_field.async_unit_error,
                              sft_reg.bit_field.profiler_unit_error,
                              sft_reg.bit_field.enable_unit_error,
                              sft_reg.bit_field.adc_sys_pll_lock,
                              sft_reg.bit_field.mcu_subsystem_error,
                              sft_reg.bit_field.mipi_error,
                              sft_reg.bit_field.ssi_error,
                              sft_reg.bit_field.synthesizer_lock,
                              sft_reg.bit_field.safety_unit,
                              sft_reg.bit_field.safety_error,
                              sft_reg.bit_field.safety_error};
#else
   uint8_t sft_reg_arr[] = {sft_reg.bit_field.bor_power_error,
                            sft_reg.bit_field.reference_pll_lock,
                            sft_reg.bit_field.mcu_error,
                            sft_reg.bit_field.synthesizer_error,
                            sft_reg.bit_field.rx_adc,
                            sft_reg.bit_field.frame_unit_error,
                            sft_reg.bit_field.async_unit_error,
                            sft_reg.bit_field.profiler_unit_error,
                            sft_reg.bit_field.enable_unit_error,
                            sft_reg.bit_field.adc_sys_pll_lock,
                            sft_reg.bit_field.mcu_subsystem_error,
                            sft_reg.bit_field.mipi_error,
                            sft_reg.bit_field.ssi_error,
                            sft_reg.bit_field.synthesizer_lock,
                            sft_reg.bit_field.safety_unit,
                            sft_reg.bit_field.safety_error};
#endif
   for (uint8_t idx = 0; idx < sizeof(sft_reg_arr); idx++)
   {
      if (BIT_SET == sft_reg_arr[idx])
      {
         switch (idx)
         {
            case 0:
               Handle_Bor_Power_Error();
               break;
            case 1:
               Handle_Reference_Pll_Lock_Error();
               break;
            case 2:
               Handle_MCU_Error();
               break;
            case 3:
               Handle_Synthesizer_Error();
               break;
            case 4:
               Handle_Rx_ADC_Error();
               break;
            case 5:
               Handle_Frame_Unit_Error();
               break;
            case 6:
               Handle_Async_Unit_Error();
               break;
            case 7:
               Handle_Profiler_Unit_Error();
               break;
            case 8:
               Handle_Enable_Unit_Error();
               break;
            case 9:
               Handle_ADC_SYS_PLL_Lock_Error();
               break;
            case 10:
               Handle_MCU_Subsystem_Error();
               break;
            case 11:
               Handle_MIPI_Error();
               break;
            case 12:
               Handle_SSI_Error();
               break;
            case 13:
               Handle_Synthesizer_Lock_Error();
               break;
            case 14:
               Handle_Safety_Unit_Error();
               break;
            case 15:
               Handle_Safety_Error();
               break;
            default:
               break;
         }
      }
   }

   MMIC_FuSa_Backup_Active_Faults();
}

/*===========================================================================*\
 * FUNCTION: MMIC_FuSa_Backup_Active_Faults
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Snapshot currently decoded FuSa active faults into backup storage.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void MMIC_FuSa_Backup_Active_Faults(void)
{
   int idx                                  = 0;
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   FuSa_Faults_Union_T *fusa_backup_flt_ptr = Get_Mmic_Fusa_Backup_Fault_Ptr();

   for (idx = 0; idx < RFE_FUSA_FAULTS_MAX; idx++)
   {
      fusa_backup_flt_ptr->arr_val[idx] |= fusa_active_flt_ptr->arr_val[idx];
      MMIC_Stream.MMIC_Data.MMIC_Fusa_Active_Fault[idx] = fusa_active_flt_ptr->arr_val[idx];
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Bor_Power_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the BOR power error by checking the SFT_STATUS register and updating the corresponding FSM state.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Bor_Power_Error(void)
{
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint32_t core_bank_sft_status            = MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_STATUS;
   if (0x2 == (core_bank_sft_status & 0x3)) // Check SFT_STATUS[1:0] = 2b’10
   {
      fusa_active_flt_ptr->fusa_fault_bits.sm_031_pmu_bor = BIT_SET;
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Reference_Pll_Lock_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the Reference PLL lock error by checking the CPLL_BANK_REFPLL_ERR and CPLL_BANK_REFPLL_ERR_RED registers
 *and updating the corresponding FSM state.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Reference_Pll_Lock_Error(void)
{
   uint32_t cpll_refpll_err          = MMIC_Stream.MMIC_Data.mmic_bist_status.CPLL_BANK_REFPLL_ERR;
   uint32_t cpll_bank_refpll_err_red = 0;
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_CPLL_BANK_REFPLL_ERR_RED, &cpll_bank_refpll_err_red);
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {(MMIC_BIT_SET(cpll_refpll_err, BIT_0) && MMIC_BIT_SET(cpll_refpll_err, BIT_8)),
                             (MMIC_BIT_SET(cpll_refpll_err, BIT_4) && MMIC_BIT_SET(cpll_refpll_err, BIT_12)),
                             ((MMIC_BIT_SET(cpll_refpll_err, BIT_5)) && (MMIC_BIT_SET(cpll_refpll_err, BIT_13))),
                             (MMIC_BIT_SET(cpll_refpll_err, BIT_1) && MMIC_BIT_SET(cpll_refpll_err, BIT_9))};

   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_014_regs_data_parity = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_016_regs_ctrl_redundancy = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_026_cpll_lock = BIT_SET;
               break;
            case 3U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_003_mcu_ahb_parity = BIT_SET;
               break;
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_MCU_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the MCU error by checking various error status registers and updating the corresponding FSM states based
 *on the specific error conditions.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_MCU_Error(void)
{
   uint32_t dbg_core_bank_mcu_sts_mcu_mssg = MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_MCU_STS_MCU_MSSG;
   uint32_t core_bank_mcu_det_sft_err      = 0;
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_CORE_BANK_MCU_DET_SFT_ERR, &core_bank_mcu_det_sft_err);
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {
      (DOUBLE_BIT_CHECK(dbg_core_bank_mcu_sts_mcu_mssg, BIT_2, 3) &&
       DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[0], BIT_2, 1)), // sm_015_regs_data_readback
      (DOUBLE_BIT_CHECK(dbg_core_bank_mcu_sts_mcu_mssg, 2, 3) &&
       DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[1], BIT_2, 1)), // sm_022_otpm_crc
      (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[3], BIT_10, 1)), // sm_056_rxadc_samples_prbs
      ((DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[17], BIT_4, 1)) ||
       (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[17], BIT_6, 1))) // sm_038_sadcpvt_parity
   };
   uint8_t index = 0U;
   // mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_CPU_SYS_MLBX_STATUS, &mlbx_status);
   for (index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_015_regs_data_readback = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_022_otpm_crc = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_056_rxadc_samples_prbs = BIT_SET;
               break;
            case 3U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_038_sadcpvt_parity = BIT_SET;
               break;
         }
      }
   }

   if (dbg_core_bank_mcu_sts_mcu_mssg == 4)
   {
      uint8_t sm_fault_arr_msg[] = {
         ((DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[6], BIT_4, 1)) ||
          (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[6], BIT_6, 1)) ||
          (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[6], BIT_8, 1)) ||
          //(DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[6], BIT_10, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[7], BIT_11, 2, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[8], BIT_11, 2, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[9], BIT_11, 2, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[10], BIT_5, 2, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[10] >> BIT_8, (BIT_11 - BIT_8), 2,
                              1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[11], BIT_9, 2,
                              1))), // sm_032_vddxx_vmonov,

         ((DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[11], BIT_10, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[12], BIT_3, 2, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[12] >> BIT_6, (BIT_11 - BIT_6), 2,
                              1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[13], BIT_11, 2, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[14], BIT_11, 2, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[15], BIT_11, 2, 1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[16] >> BIT_2, (BIT_11 - BIT_2), 2,
                              1)) ||
          (MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[17], BIT_3, 2,
                              1))), // sm_033_vddxx_vmonuv

         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[17], BIT_10, 1) ||
          MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[18], BIT_11, 2, 1) ||
          MULTIPLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[19], BIT_5, 2,
                             1)), // sm_035_currref_imon
         ((DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[2], BIT_4, 1)) ||
          (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[2], BIT_2, 1))), // sm_036_thermal_mon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[0], BIT_6, 1)), // sm_037_pvt_plausibility
         ((DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[17], BIT_4, 1)) ||
          (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[17], BIT_6, 1))), // sm_038_sadcpvt_parity
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[2], BIT_8, 1)),    // sm_039_vco_powermon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[1], BIT_10,
                           1)), // sm_040_quadrupler_powermon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[4], BIT_0, 1)),   // sm_072_rx_ampmon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[0], BIT_4, 1)),   // sm_074_rx_noisemon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[19], BIT_8, 1)),  // sm_075_rx_relampmon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[19], BIT_10, 1)), // sm_076_rx_relphasemon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[3], BIT_6, 1)),   // sm_077_rx_iqimbmon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[19], BIT_6, 1)),  // sm_082_tx_relphasemon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[3], BIT_8, 1)),   // sm_083_tx_relampmon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[1], BIT_4, 1)),   // sm_085_tx_inc_powermon
         (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[1], BIT_6, 1)),   // sm_086_tx_recphasemon
      };

      for (index = 0U; index < sizeof(sm_fault_arr_msg); index++)
      {
         if (sm_fault_arr_msg[index])
         {
            switch (index)
            {
               case 0U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_032_vddxx_vmonov = BIT_SET;
                  break;
               case 1U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_033_vddxx_vmonuv = BIT_SET;
                  break;
               case 2U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_035_currref_imon = BIT_SET;
                  break;
               case 3U:
                  // update for low_temp and over_temp fault bits
                  (DOUBLE_BIT_CHECK(MMIC_Stream.MMIC_Data.mmic_bist_status.mcu_diag_error_values[2], BIT_4, 1)) ?
                     (MMIC_Low_Temp_Fault = CODED_TRUE) :
                     (MMIC_High_Temp_Fault = CODED_TRUE);
                  fusa_active_flt_ptr->fusa_fault_bits.sm_036_thermal_mon = BIT_SET;
                  break;
               case 4U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_037_pvt_plausibility = BIT_SET;
                  break;
               case 5U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_038_sadcpvt_parity = BIT_SET;
                  break;
               case 6U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_039_vco_powermon = BIT_SET;
                  break;
               case 7U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_040_quadrupler_powermon = BIT_SET;
                  break;
               case 8U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_072_rx_ampmon = BIT_SET;
                  break;
               case 9U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_074_rx_noisemon = BIT_SET;
                  break;
               case 10U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_075_rx_relampmon = BIT_SET;
                  break;
               case 11U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_076_rx_relphasemon = BIT_SET;
                  break;
               case 12U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_077_rx_ifvga_freqmon = BIT_SET;
                  break;
               case 13U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_082_tx_relphasemon = BIT_SET;
                  break;
               case 14U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_083_tx_relampmon = BIT_SET;
                  break;
               case 15U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_085_tx_inc_powermon = BIT_SET;
                  break;
               case 16U:
                  fusa_active_flt_ptr->fusa_fault_bits.sm_086_tx_recphasemon = BIT_SET;
                  break;
               default:
                  break;
            }
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Synthesizer_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the LOGEN error by checking the LOGEN_BANK_LOGEN_ERROR, LOGEN_BANK_LOGEN_ERR_RED,
 *LOGEN_BANK_CHRP_GEN_ERROR, and LOGEN_BANK_CHRP_GEN_ERR_RED registers and updating the corresponding FSM state.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Synthesizer_Error(void)
{
   uint32_t logen_bank_logen_err_red        = 0;
   uint32_t core_bank_logen_ref_clock_lock  = 0;
   uint32_t logen_bank_chrp_gen_err_red     = 0;
   uint32_t dbg_logen_bank_chrp_gen_error   = MMIC_Stream.MMIC_Data.mmic_bist_status.LOGEN_BANK_CHRP_GEN_ERROR;
   uint32_t logen_error                     = MMIC_Stream.MMIC_Data.mmic_bist_status.LOGEN_BANK_LOGEN_ERROR;
   uint32_t core_sft_err_status             = MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_STATUS;
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();

   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_LOGEN_BANK_LOGEN_ERR_RED, &logen_bank_logen_err_red);
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_CORE_BANK_LOGEN_REF_CLOCK_LOCK, &core_bank_logen_ref_clock_lock);
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_LOGEN_BANK_CHRP_GEN_ERR_RED, &logen_bank_chrp_gen_err_red);

   uint8_t sm_fault_arr[] = {
      (core_bank_logen_ref_clock_lock == 2U),
      ((logen_error & 0x1F) == 0x1F) && ((logen_error & 0x1F00) == 0x1F00),
      (MMIC_BIT_SET(dbg_logen_bank_chrp_gen_error, BIT_0) && MMIC_BIT_SET(dbg_logen_bank_chrp_gen_error, BIT_8)),
      (MMIC_BIT_SET(core_sft_err_status, BIT_2) && MMIC_BIT_SET(core_sft_err_status, BIT_15)),
      ((MMIC_BIT_SET(dbg_logen_bank_chrp_gen_error, BIT_3)) && (MMIC_BIT_SET(dbg_logen_bank_chrp_gen_error, BIT_11))),
      (MMIC_BIT_SET(dbg_logen_bank_chrp_gen_error, BIT_1) && (MMIC_BIT_SET(dbg_logen_bank_chrp_gen_error, BIT_9)) &&
       (MMIC_BIT_SET(dbg_logen_bank_chrp_gen_error, BIT_2)) && (MMIC_BIT_SET(dbg_logen_bank_chrp_gen_error, BIT_10)))};

   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_029_clkcore_comp = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_003_mcu_ahb_parity       = BIT_SET;
               fusa_active_flt_ptr->fusa_fault_bits.sm_014_regs_data_parity     = BIT_SET;
               fusa_active_flt_ptr->fusa_fault_bits.sm_016_regs_ctrl_redundancy = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_025_fsm_mon = BIT_SET;
               break;
            case 3U:
            case 4U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_045_profiler_bus_parity = BIT_SET;
               break;
            case 5U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_100_chirpgen_mmd_fifo_ouflow = BIT_SET;
               break;
            default:
               break;
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Rx_ADC_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the Rx ADC error by checking the RXADC_MOD registers and updating the corresponding FSM state.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Rx_ADC_Error(void)
{
   uint32_t dbg_rxadc_fusairqv0 = MMIC_Stream.MMIC_Data.mmic_bist_status.RXADC_FUSAIRQV0;
   uint32_t dbg_rxadc_fusairqv1 = MMIC_Stream.MMIC_Data.mmic_bist_status.RXADC_FUSAIRQV1;

   /* Load RXADC MOD registers on-demand (only in this section) */
   mars_reg_value_t rxadc_mod0_fusairqv_fusairqv0 = 0;
   mars_reg_value_t rxadc_mod0_fusairqv_fusairqv1 = 0;
   mars_reg_value_t rxadc_mod1_fusairqv_fusairqv0 = 0;
   mars_reg_value_t rxadc_mod1_fusairqv_fusairqv1 = 0;
   mars_reg_value_t rxadc_mod2_fusairqv_fusairqv0 = 0;
   mars_reg_value_t rxadc_mod2_fusairqv_fusairqv1 = 0;
   mars_reg_value_t rxadc_mod3_fusairqv_fusairqv0 = 0;
   mars_reg_value_t rxadc_mod3_fusairqv_fusairqv1 = 0;

   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_RXADC_MOD0_FUSAIRQV0, &rxadc_mod0_fusairqv_fusairqv0);
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_RXADC_MOD0_FUSAIRQV1, &rxadc_mod0_fusairqv_fusairqv1);
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_RXADC_MOD1_FUSAIRQV0, &rxadc_mod1_fusairqv_fusairqv0);
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_RXADC_MOD1_FUSAIRQV1, &rxadc_mod1_fusairqv_fusairqv1);
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_RXADC_MOD2_FUSAIRQV0, &rxadc_mod2_fusairqv_fusairqv0);
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_RXADC_MOD2_FUSAIRQV1, &rxadc_mod2_fusairqv_fusairqv1);
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_RXADC_MOD3_FUSAIRQV0, &rxadc_mod3_fusairqv_fusairqv0);
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_RXADC_MOD3_FUSAIRQV1, &rxadc_mod3_fusairqv_fusairqv1);

   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();

   uint8_t sm_fault_arr[] = {
      ((MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_4) && MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_12)) ||
       (MMIC_BIT_SET(rxadc_mod0_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod0_fusairqv_fusairqv0, BIT_8)) ||
       (MMIC_BIT_SET(rxadc_mod1_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod1_fusairqv_fusairqv0, BIT_8)) ||
       (MMIC_BIT_SET(rxadc_mod2_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod2_fusairqv_fusairqv0, BIT_8)) ||
       (MMIC_BIT_SET(rxadc_mod3_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod3_fusairqv_fusairqv0, BIT_8))),
      ((MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_5) && MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_13)) ||
       (MMIC_BIT_SET(rxadc_mod0_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod0_fusairqv_fusairqv0, BIT_8)) ||
       (MMIC_BIT_SET(rxadc_mod1_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod1_fusairqv_fusairqv0, BIT_8)) ||
       (MMIC_BIT_SET(rxadc_mod2_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod2_fusairqv_fusairqv0, BIT_8)) ||
       (MMIC_BIT_SET(rxadc_mod3_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod3_fusairqv_fusairqv0, BIT_8))),
      ((MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_6) && MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_14)) ||
       (MMIC_BIT_SET(rxadc_mod0_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod0_fusairqv_fusairqv0, BIT_8)) ||
       (MMIC_BIT_SET(rxadc_mod1_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod1_fusairqv_fusairqv0, BIT_8)) ||
       (MMIC_BIT_SET(rxadc_mod2_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod2_fusairqv_fusairqv0, BIT_8)) ||
       (MMIC_BIT_SET(rxadc_mod3_fusairqv_fusairqv0, BIT_0) && MMIC_BIT_SET(rxadc_mod3_fusairqv_fusairqv0, BIT_8))),
      (MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_3) && MMIC_BIT_SET(dbg_rxadc_fusairqv1, BIT_11))};

   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_003_mcu_ahb_parity = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_014_regs_data_parity = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_016_regs_ctrl_redundancy = BIT_SET;
               break;
            case 3U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_045_profiler_bus_parity = BIT_SET;
               break;
            default:
               break;
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Frame_Unit_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the Frame Unit error by checking the DBG_CORE_BANK_FRM_ERR register and updating the corresponding FSM
 *state.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Frame_Unit_Error(void)
{
   uint32_t dbg_core_bank_frm_err           = MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_FRM_ERR;
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {
      (MMIC_BIT_SET(dbg_core_bank_frm_err, BIT_3) &&
       MMIC_BIT_SET(dbg_core_bank_frm_err, BIT_7)), // sm_013_mcu_frame_monitor, sm_042_frame_timermon
      (MMIC_BIT_SET(dbg_core_bank_frm_err, BIT_1) && MMIC_BIT_SET(dbg_core_bank_frm_err, BIT_5)), // sm_025_fsm_mon
      (MMIC_BIT_SET(dbg_core_bank_frm_err, BIT_0) && MMIC_BIT_SET(dbg_core_bank_frm_err, BIT_4))}; // sm_093_frame_timer_redundancy

   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_013_mcu_frame_monitor = BIT_SET;
               fusa_active_flt_ptr->fusa_fault_bits.sm_042_frame_timermon    = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_025_fsm_mon = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_093_frame_timer_redundancy = BIT_SET;
               break;
            default:
               break;
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Async_Unit_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the Async Unit error by checking the ASYNC_ERR1 and ASYNC_BANK_ASYNC_ERR_RED registers and updating the
 *corresponding FSM state.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Async_Unit_Error(void)
{
   uint32_t async_err1               = MMIC_Stream.MMIC_Data.mmic_bist_status.ASYNC_BANK_ASYNC_ERR1;
   uint32_t async_bank_async_err_red = 0;
   uint32_t dbg_prof_bank_prf1       = MMIC_Stream.MMIC_Data.mmic_bist_status.PROF_BANK_PRF_ERR1;
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_ASYNC_BANK_ASYNC_ERR_RED, &async_bank_async_err_red);
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {
      (MMIC_BIT_SET(async_err1, BIT_1) && MMIC_BIT_SET(async_err1, BIT_17)), // sm_014_regs_data_parity
      (MMIC_BIT_SET(async_err1, BIT_8) && MMIC_BIT_SET(async_err1, BIT_24)), // sm_003_mcu_ahb_parity
      (MMIC_BIT_SET(async_err1, BIT_2) && MMIC_BIT_SET(async_err1, BIT_18)), // sm_023_buff_overflow
      (((MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_4)) && (MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_12))) ||
       (MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_2) && MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_10))), // sm_024_buff_underflow
      (MMIC_BIT_SET(async_err1, BIT_7) && MMIC_BIT_SET(async_err1, BIT_23)),                   // sm_025_fsm_mon
      (MMIC_BIT_SET(async_err1, BIT_4) && MMIC_BIT_SET(async_bank_async_err_red, BIT_20)), // sm_045_profiler_bus_parity
      (MMIC_BIT_SET(async_err1, BIT_5) && MMIC_BIT_SET(async_err1, BIT_21)), // sm_052_async_pixel_counterchk
      (MMIC_BIT_SET(async_err1, BIT_2) && MMIC_BIT_SET(async_err1, BIT_18) && MMIC_BIT_SET(async_err1, BIT_6) &&
       MMIC_BIT_SET(async_err1, BIT_22)),                                     // sm_053_async_ram_overflow
      (MMIC_BIT_SET(async_err1, BIT_0) && MMIC_BIT_SET(async_err1, BIT_16)),  // sm_055_rxadc_datavalid_checker
      (MMIC_BIT_SET(async_err1, BIT_3) && MMIC_BIT_SET(async_err1, BIT_19)),  // sm_058_rxadc_samples_parity
      (MMIC_BIT_SET(async_err1, BIT_10) && MMIC_BIT_SET(async_err1, BIT_26)), // sm_060_mipi_csi_laneserror
      (MMIC_BIT_SET(async_err1, BIT_4) && MMIC_BIT_SET(async_err1, BIT_20))   // sm_088_async_cmdfifo_parity
   };

   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_014_regs_data_parity = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_003_mcu_ahb_parity = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_023_buff_overflow = BIT_SET;
               break;
            case 3U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_024_buff_underflow = BIT_SET;
               break;
            case 4U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_025_fsm_mon = BIT_SET;
               break;
            case 5U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_045_profiler_bus_parity = BIT_SET;
               break;
            case 6U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_052_async_pixel_counterchk = BIT_SET;
               break;
            case 7U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_053_async_ram_overflow = BIT_SET;
               break;
            case 8U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_055_rxadc_datavalid_checker = BIT_SET;
               break;
            case 9U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_058_rxadc_samples_parity = BIT_SET;
               break;
            case 10U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_060_mipi_csi_laneserror = BIT_SET;
               break;
            case 11U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_088_async_cmdfifo_parity = BIT_SET;
               break;
            default:
               break;
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Profiler_Unit_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the Profiler Unit error by checking the PROF_BANK_PRF_ERR1 and PROFILER_BANK_PRF_ERR_RED registers and
 *updating the corresponding FSM state.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Profiler_Unit_Error(void)
{
   uint32_t dbg_prof_bank_prf1        = MMIC_Stream.MMIC_Data.mmic_bist_status.PROF_BANK_PRF_ERR1;
   uint32_t profiler_bank_prf_err_red = 0;
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_PROFILER_BANK_PRF_ERR_RED, &profiler_bank_prf_err_red);
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {
      (MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_6) && MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_14)), // sm_025_fsm_mon
      (MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_0) && MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_8)), // sm_043_profiler_shadowregs_parity
      (MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_3) && MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_11)), // sm_046_profiler_fifo_emptychk
      (MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_5) && MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_13))}; // sm_047_profiler_fifo_overflowchk

   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_025_fsm_mon = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_043_profiler_shadowregs_parity = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_046_profiler_fifo_emptychk = BIT_SET;
               break;
            case 3U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_047_profiler_fifo_overflowchk = BIT_SET;
               break;
            default:
               break;
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Enable_Unit_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the Enable Unit error by checking the CORE_BANK_ENA_ERR register and updating the corresponding FSM state.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Enable_Unit_Error(void)
{
   uint32_t core_ena_err                    = MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_ENA_ERR;
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {
      ((MMIC_BIT_SET(core_ena_err, BIT_7) && MMIC_BIT_SET(core_ena_err, BIT_15))), // sm_003_mcu_ahb_parity
      (MMIC_BIT_SET(core_ena_err, BIT_0) && MMIC_BIT_SET(core_ena_err, BIT_8)),    // sm_025_fsm_mon
      (MMIC_BIT_SET(core_ena_err, BIT_3) && MMIC_BIT_SET(core_ena_err, BIT_11)),   // sm_041_ctrlsig_redundant
      (MMIC_BIT_SET(core_ena_err, BIT_2) && MMIC_BIT_SET(core_ena_err, BIT_10)),   // sm_045_profiler_bus_parity
      (MMIC_BIT_SET(core_ena_err, BIT_1) && MMIC_BIT_SET(core_ena_err, BIT_9)), // sm_048_enable_lut_phaseparity
      (MMIC_BIT_SET(core_ena_err, BIT_1) && MMIC_BIT_SET(core_ena_err, BIT_9)), // sm_049_enable_lut_indexchecker
      (MMIC_BIT_SET(core_ena_err, BIT_3) && MMIC_BIT_SET(core_ena_err, BIT_11)), // sm_051_enable_scheduler_redundant
      (MMIC_BIT_SET(core_ena_err, BIT_6) && MMIC_BIT_SET(core_ena_err, BIT_14))}; // sm_092_enable_fifo_ouflow

   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_003_mcu_ahb_parity = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_025_fsm_mon = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_041_ctrlsig_redundant = BIT_SET;
               break;
            case 3U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_045_profiler_bus_parity = BIT_SET;
               break;
            case 4U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_048_enable_lut_phaseparity = BIT_SET;
               break;
            case 5U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_049_enable_lut_indexchecker = BIT_SET;
               break;
            case 6U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_051_enable_scheduler_redundant = BIT_SET;
               break;
            case 7U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_092_enable_fifo_ouflow = BIT_SET;
               break;
            default:
               break;
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_ADC_SYS_PLL_Lock_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the ADC SYS PLL lock error by checking the RXADC_FUSAIRQV0 and RXADC_FUSAIRQV1 registers and updating the
 *corresponding FSM state.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_ADC_SYS_PLL_Lock_Error(void)
{
   uint32_t dbg_rxadc_fusairqv0             = MMIC_Stream.MMIC_Data.mmic_bist_status.RXADC_FUSAIRQV0;
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();

   if ((MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_1) && MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_9)) ||
       (MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_0) && MMIC_BIT_SET(dbg_rxadc_fusairqv0, BIT_8)))
   {
      fusa_active_flt_ptr->fusa_fault_bits.sm_028_spll_lock = BIT_SET;
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_MCU_Subsystem_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the MCU Subsystem error by checking various MCU error registers and updating the corresponding FSM state
 *based on the error conditions.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_MCU_Subsystem_Error(void)
{
   uint32_t dbg_prof_bank_prf1        = MMIC_Stream.MMIC_Data.mmic_bist_status.PROF_BANK_PRF_ERR1;
   uint32_t profiler_bank_prf_err_red = 0;
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_PROFILER_BANK_PRF_ERR_RED, &profiler_bank_prf_err_red);
   uint32_t mcu_cpu_sys_mcu_err_1_red = 0;
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_CPU_SYS_MCU_ERR_1_RED, &mcu_cpu_sys_mcu_err_1_red);
   uint32_t mcu_err_0                 = MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_MCU_ERR_0;
   uint32_t mcu_err_1                 = MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_MCU_ERR_1;
   uint32_t mcu_err_2                 = MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_MCU_ERR_2;
   uint32_t mcu_err_3                 = MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_MCU_ERR_3;
   uint32_t mcu_dma_err               = MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_DMA_ERR;
   uint32_t mcu_cpu_sys_mcu_err_2_red = 0;
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_CPU_SYS_MCU_ERR_2_RED, &mcu_cpu_sys_mcu_err_2_red);
   uint32_t mcu_cpu_sys_mcu_err_0_red = 0;
   mars_read_register(&Mars_Self_Layer2_InstanceDriver0, MARS_F_CPU_SYS_MCU_ERR_0_RED, &mcu_cpu_sys_mcu_err_0_red);
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {
      ((MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_7) && MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_15)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_13) && MMIC_BIT_SET(mcu_err_1, BIT_29))), // sm_014_regs_data_parity
      ((MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_7) && MMIC_BIT_SET(profiler_bank_prf_err_red, BIT_7)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_13) && MMIC_BIT_SET(mcu_cpu_sys_mcu_err_1_red, BIT_13))), // sm_016_regs_ctrl_redundancy
      (MMIC_BIT_SET(mcu_err_0, BIT_0) && MMIC_BIT_SET(mcu_err_0, BIT_16) && MMIC_BIT_SET(mcu_err_3, BIT_12) &&
       MMIC_BIT_SET(mcu_err_3, BIT_28)),                                   // sm_001_mcu_cpu_dcls
      (MMIC_BIT_SET(mcu_err_0, BIT_6) && MMIC_BIT_SET(mcu_err_0, BIT_22)), // sm_002_deprecated
      ((MMIC_BIT_SET(mcu_err_1, BIT_15) && MMIC_BIT_SET(mcu_err_1, BIT_31)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_0) && MMIC_BIT_SET(mcu_err_2, BIT_16)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_1) && MMIC_BIT_SET(mcu_err_2, BIT_17)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_4) && MMIC_BIT_SET(mcu_err_2, BIT_20)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_5) && MMIC_BIT_SET(mcu_err_2, BIT_21)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_6) && MMIC_BIT_SET(mcu_err_2, BIT_22)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_7) && MMIC_BIT_SET(mcu_err_2, BIT_23)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_14) && MMIC_BIT_SET(mcu_err_1, BIT_30)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_8) && MMIC_BIT_SET(mcu_err_2, BIT_24)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_9) && MMIC_BIT_SET(mcu_err_2, BIT_25)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_10) && MMIC_BIT_SET(mcu_err_2, BIT_26)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_3) && MMIC_BIT_SET(mcu_err_2, BIT_19)) ||
       (MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_7) && MMIC_BIT_SET(dbg_prof_bank_prf1, BIT_15))), // sm_003_mcu_ahb_parity
      ((MMIC_BIT_SET(mcu_err_2, BIT_2) && MMIC_BIT_SET(mcu_err_2, BIT_18)) ||
       (MMIC_BIT_SET(mcu_err_2, BIT_12) && MMIC_BIT_SET(mcu_err_2, BIT_28))), // sm_004_mcu_ahb_timeout
      ((MMIC_BIT_SET(mcu_err_3, BIT_5) && MMIC_BIT_SET(mcu_err_3, BIT_21)) &&
       (MMIC_BIT_SET(mcu_err_3, BIT_6) && MMIC_BIT_SET(mcu_err_3, BIT_22)) &&
       (MMIC_BIT_SET(mcu_err_3, BIT_7) && MMIC_BIT_SET(mcu_err_3, BIT_23))), // sm_005_mcu_ahb_cdcmon
      (MMIC_BIT_SET(mcu_err_0, BIT_2) &&
       MMIC_BIT_SET(mcu_err_0, BIT_18)), // sm_006_mcu_mailbox_overflow  and sm_007_mcu_mailbox_underflow
      ((MMIC_BIT_SET(mcu_err_0, BIT_7) && MMIC_BIT_SET(mcu_err_0, BIT_23)) ||
       (MMIC_BIT_SET(mcu_dma_err, BIT_8) && MMIC_BIT_SET(mcu_dma_err, BIT_12)) ||
       (MMIC_BIT_SET(mcu_dma_err, BIT_9) && MMIC_BIT_SET(mcu_dma_err, BIT_15)) ||
       (MMIC_BIT_SET(mcu_dma_err, BIT_10) && MMIC_BIT_SET(mcu_dma_err, BIT_16)) ||
       (MMIC_BIT_SET(mcu_dma_err, BIT_11) && MMIC_BIT_SET(mcu_dma_err, BIT_17)) ||
       (MMIC_BIT_SET(mcu_dma_err, BIT_13) && MMIC_BIT_SET(mcu_dma_err, BIT_19))), // sm_012_mcu_dma_red
      ((MMIC_BIT_SET(mcu_err_0, BIT_12) && MMIC_BIT_SET(mcu_err_0, BIT_28)) ||
       (MMIC_BIT_SET(mcu_err_0, BIT_13) && MMIC_BIT_SET(mcu_err_0, BIT_29)) ||
       (MMIC_BIT_SET(mcu_err_3, BIT_3) && MMIC_BIT_SET(mcu_err_3, BIT_19))), // sm_017_dram_ecc
      ((MMIC_BIT_SET(mcu_err_0, BIT_10) && MMIC_BIT_SET(mcu_err_0, BIT_26)) ||
       (MMIC_BIT_SET(mcu_err_3, BIT_2) && MMIC_BIT_SET(mcu_err_3, BIT_18)) ||
       (MMIC_BIT_SET(mcu_err_0, BIT_11) && MMIC_BIT_SET(mcu_err_0, BIT_27))), // sm_018_iram_ecc
      ((MMIC_BIT_SET(mcu_err_0, BIT_8) && MMIC_BIT_SET(mcu_err_0, BIT_24)) ||
       (MMIC_BIT_SET(mcu_err_0, BIT_9) && MMIC_BIT_SET(mcu_err_0, BIT_25))), // sm_019_irom_ecc
      ((MMIC_BIT_SET(mcu_err_0, BIT_14) && MMIC_BIT_SET(mcu_err_0, BIT_30)) ||
       (MMIC_BIT_SET(mcu_err_3, BIT_4) && MMIC_BIT_SET(mcu_err_3, BIT_20)) ||
       (MMIC_BIT_SET(mcu_err_0, BIT_15) && MMIC_BIT_SET(mcu_err_0, BIT_31))), // sm_020_pram_ecc
      ((MMIC_BIT_SET(mcu_err_2, BIT_14) && MMIC_BIT_SET(mcu_err_2, BIT_30))) ||
         ((MMIC_BIT_SET(mcu_dma_err, BIT_12) && MMIC_BIT_SET(mcu_dma_err, BIT_18))), // sm_025_fsm_mon
      ((MMIC_BIT_SET(mcu_err_0, BIT_3) && MMIC_BIT_SET(mcu_err_0, BIT_19)) ||
       (MMIC_BIT_SET(mcu_err_0, BIT_5) && MMIC_BIT_SET(mcu_err_0, BIT_21))), // sm_090_mcu_mailbox_indexparity
      ((MMIC_BIT_SET(mcu_err_1, BIT_6) && MMIC_BIT_SET(mcu_err_1, BIT_22)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_7) && MMIC_BIT_SET(mcu_err_1, BIT_23)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_8) && MMIC_BIT_SET(mcu_err_1, BIT_24)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_9) && MMIC_BIT_SET(mcu_err_1, BIT_25)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_10) && MMIC_BIT_SET(mcu_err_1, BIT_26)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_11) && MMIC_BIT_SET(mcu_err_1, BIT_27))), // sm_094_ssi_cmd_parity
      ((MMIC_BIT_SET(mcu_err_3, BIT_11) && MMIC_BIT_SET(mcu_err_3, BIT_27))), // sm_097_mcu_irq_cdcmon

      ((MMIC_BIT_SET(mcu_err_0, BIT_1) && MMIC_BIT_SET(mcu_err_0, BIT_17)) && MMIC_BIT_SET(mcu_err_2, BIT_12) &&
       MMIC_BIT_SET(mcu_err_2, BIT_28)) // sm_099_mcu_cpu_exception
   };
   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_014_regs_data_parity = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_016_regs_ctrl_redundancy = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_001_mcu_cpu_dcls = BIT_SET;
               break;
            case 3U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_002_deprecated = BIT_SET;
               break;
            case 4U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_003_mcu_ahb_parity = BIT_SET;
               break;
            case 5U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_004_mcu_ahb_timeout = BIT_SET;
               break;
            case 6U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_005_mcu_ahb_cdcmon = BIT_SET;
               break;
            case 7U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_006_mcu_mailbox_overflow  = BIT_SET;
               fusa_active_flt_ptr->fusa_fault_bits.sm_007_mcu_mailbox_underflow = BIT_SET;
               break;
            case 8U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_012_mcu_dma_red = BIT_SET;
               break;
            case 9U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_017_dram_ecc = BIT_SET;
               break;
            case 10U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_018_iram_ecc = BIT_SET;
               break;
            case 11U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_019_irom_ecc = BIT_SET;
               break;
            case 12U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_020_pram_ecc = BIT_SET;
               break;
            case 13U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_025_fsm_mon = BIT_SET;
               break;
            case 14U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_090_mcu_mailbox_indexparity = BIT_SET;
               break;
            case 15U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_094_ssi_cmd_parity = BIT_SET;
               break;
            case 16U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_097_mcu_irq_cdcmon = BIT_SET;
               break;
            case 17U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_099_mcu_cpu_exception = BIT_SET;
               break;
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_MIPI_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the CSI2 error by checking the MIPI_BANK_IRQ_STATUS and ASYNC_ERR1 registers and updating the
 *corresponding FSM state based on the error conditions.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_MIPI_Error(void)
{
   uint32_t mipi_bank_irq_status            = MMIC_Stream.MMIC_Data.mmic_bist_status.MIPI_BANK_IRQ_STATUS;
   uint32_t async_err1                      = MMIC_Stream.MMIC_Data.mmic_bist_status.ASYNC_BANK_ASYNC_ERR1;
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {(MMIC_BIT_SET(mipi_bank_irq_status, BIT_2) && MMIC_BIT_SET(async_err1, BIT_13) &&
                              MMIC_BIT_SET(async_err1, BIT_29)), // sm_059_mipi_csi_typeerror
                             (MMIC_BIT_SET(mipi_bank_irq_status, BIT_1) && MMIC_BIT_SET(async_err1, BIT_15) &&
                              MMIC_BIT_SET(async_err1, BIT_31)),          // sm_061_mipi_csi_ppitimeout
                             (MMIC_BIT_SET(mipi_bank_irq_status, BIT_7)), // sm_062_mipi_csi_pixelparity
                             (MMIC_BIT_SET(mipi_bank_irq_status, BIT_3) && MMIC_BIT_SET(async_err1, BIT_14) &&
                              MMIC_BIT_SET(async_err1, BIT_30)),           // sm_063_mipi_csi_csrparity
                             (MMIC_BIT_SET(mipi_bank_irq_status, BIT_11)), // sm_064_mipi_csi_interror
                             (MMIC_BIT_SET(mipi_bank_irq_status, BIT_14) && MMIC_BIT_SET(mipi_bank_irq_status, BIT_8) &&
                              MMIC_BIT_SET(async_err1, BIT_12) && MMIC_BIT_SET(async_err1, BIT_28)), // sm_065_mipi_csi_ufifoerror
                             (MMIC_BIT_SET(mipi_bank_irq_status, BIT_9)),  // sm_066_mipi_csi_headerecc
                             (MMIC_BIT_SET(mipi_bank_irq_status, BIT_10)), // sm_067_mipi_csi_wdt
                             (MMIC_BIT_SET(mipi_bank_irq_status, BIT_13)), // sm_068_mipi_csi_bist
                             (MMIC_BIT_SET(async_err1, BIT_11) && MMIC_BIT_SET(async_err1, BIT_27))}; // sm_071_dphy_plldd
   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_059_mipi_csi_typeerror = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_061_mipi_csi_ppitimeout = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_062_mipi_csi_pixelparity = BIT_SET;
               break;
            case 3U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_063_mipi_csi_csrparity = BIT_SET;
               break;
            case 4U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_064_mipi_csi_interror = BIT_SET;
               break;
            case 5U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_065_mipi_csi_ufifoerror = BIT_SET;
               break;
            case 6U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_066_mipi_csi_headerecc = BIT_SET;
               break;
            case 7U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_067_mipi_csi_wdt = BIT_SET;
               break;
            case 8U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_068_mipi_csi_bist = BIT_SET;
               break;
            case 9U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_071_dphy_plldd = BIT_SET;
               break;
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_SSI_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the SSI error by checking the MCU_ERR_1 register and updating the corresponding FSM state based on the
 *error conditions.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_SSI_Error(void)
{
   uint32_t mcu_err_1                       = MMIC_Stream.MMIC_Data.mmic_bist_status.CPU_SYS_MCU_ERR_1;
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   if ((MMIC_BIT_SET(mcu_err_1, BIT_0) && MMIC_BIT_SET(mcu_err_1, BIT_16)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_1) && MMIC_BIT_SET(mcu_err_1, BIT_17)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_2) && MMIC_BIT_SET(mcu_err_1, BIT_18)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_3) && MMIC_BIT_SET(mcu_err_1, BIT_19)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_4) && MMIC_BIT_SET(mcu_err_1, BIT_20)) ||
       (MMIC_BIT_SET(mcu_err_1, BIT_5) && MMIC_BIT_SET(mcu_err_1, BIT_21)))
   {
      fusa_active_flt_ptr->fusa_fault_bits.sm_101_mcu_ssi_inter = BIT_SET;
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Synthesizer_Lock_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the Synthesizer Lock error by checking the CORE_BANK_SFT_ERR_STATUS register and updating the
 *corresponding FSM state based on the error conditions.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Synthesizer_Lock_Error(void)
{
   uint32_t core_sft_err_status             = MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_STATUS;
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {
      ((MMIC_BIT_SET(core_sft_err_status, BIT_3)) && (MMIC_BIT_SET(core_sft_err_status, BIT_16))), // sm_027_syth_lock
      (MMIC_BIT_SET(core_sft_err_status, BIT_1) && MMIC_BIT_SET(core_sft_err_status, BIT_14)), // sm_034_chirp_linchecker
      (MMIC_BIT_SET(core_sft_err_status, BIT_11) && MMIC_BIT_SET(core_sft_err_status, BIT_24))}; // sm_081_tx_phaserot_digitalmon

   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_027_syth_lock = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_034_chirp_linchecker = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_081_tx_phaserot_digitalmon = BIT_SET;
               break;
               // For improvement in UT coverage, default case is not added
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_MMIC_Core_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the MMIC Core error by checking the CORE_BANK_SFT_ERR_STATUS register and updating the corresponding FSM
 *state based on the error conditions.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Safety_Unit_Error(void)
{
   uint32_t core_sft_err_status             = MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_ERR_STATUS;
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t sm_fault_arr[]                   = {
      ((MMIC_BIT_SET(core_sft_err_status, BIT_7)) && (MMIC_BIT_SET(core_sft_err_status, BIT_20))), // sm_003_mcu_ahb_parity
      (MMIC_BIT_SET(core_sft_err_status, BIT_6) && MMIC_BIT_SET(core_sft_err_status, BIT_19)), // sm_014_regs_data_parity
      (MMIC_BIT_SET(core_sft_err_status, BIT_10) && MMIC_BIT_SET(core_sft_err_status, BIT_23)), // sm_016_regs_ctrl_redundancy
      (MMIC_BIT_SET(core_sft_err_status, BIT_12) && MMIC_BIT_SET(core_sft_err_status, BIT_25))}; // sm_030_clksys_comp

   for (uint8_t index = 0U; index < sizeof(sm_fault_arr); index++)
   {
      if (sm_fault_arr[index])
      {
         switch (index)
         {
            case 0U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_003_mcu_ahb_parity = BIT_SET;
               break;
            case 1U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_014_regs_data_parity = BIT_SET;
               break;
            case 2U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_016_regs_ctrl_redundancy = BIT_SET;
               break;
            case 3U:
               fusa_active_flt_ptr->fusa_fault_bits.sm_030_clksys_comp = BIT_SET;
               break;
               // For improvement in UT coverage, default case is not added
         }
      }
   }
}
/*===========================================================================*\
 * FUNCTION: Handle_Safety_Error
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function handles the Safety error by checking the CORE_BANK_SFT_STATUS register and updating the corresponding FSM state
 *based on the error conditions.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
static void Handle_Safety_Error(void)
{
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint32_t core_bank_sft_status            = MMIC_Stream.MMIC_Data.mmic_bist_status.CORE_BANK_SFT_STATUS;
   if ((((core_bank_sft_status >> BIT_11) & 0x7) == 0x7) ||
       (((core_bank_sft_status >> BIT_6) & 0x1F) == 0x10)) // Check SFT_STATUS[1:0] = 2b’10
   {
      fusa_active_flt_ptr->fusa_fault_bits.sm_087_dft_lbist     = BIT_SET;
      fusa_active_flt_ptr->fusa_fault_bits.sm_091_dft_mbist     = BIT_SET;
      fusa_active_flt_ptr->fusa_fault_bits.sm_096_dft_lbist_mon = BIT_SET;
   }
}
/*===========================================================================*\
 * FUNCTION: Get_MMIC_Sensor_Dead_Fault
 *===========================================================================
 * RETURN VALUE:
 *    CODED TRUE/CODE FALSE
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function returns the Sensor Dead Fault  status
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
uint8_t Get_MMIC_Sensor_Dead_Fault(void)
{
   if ((MMIC_SENSOR_DEAD_FAULT_THRESHOLD <= Sensor_Dead_Fault_Error_Count) || (CODED_TRUE == Get_MMIC_Daq_Over_Flow_Fault()))
   {
      MMIC_Sensor_Dead_Fault = CODED_TRUE;
   }
   else
   {
      MMIC_Sensor_Dead_Fault = CODED_FALSE;
   }
   return (MMIC_Sensor_Dead_Fault);
}

#pragma clang section bss = ".bss"

/*===========================================================================*\
 * FUNCTION: Get_MMIC_API_Look_Complete_Fault
 *===========================================================================
 * RETURN VALUE:
 *   uint8_t
 *  Success - true, Failure - false
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT: This function checks Look Complete Fault status from API failure status
 * --------------------------------------------------------------------------
 \*===========================================================================*/
uint8_t Get_MMIC_API_Fault(uint8_t fault_index)
{
   uint8_t ret_val;
   if (fault_index < MAX_API_FAULT_TYPE)
   {
      ret_val = MMIC_API_Failure_Status[fault_index];
   }
   else
   {
      ret_val = 0xFF; /* Invalid index */
   }
   return ret_val;
}
/*===========================================================================*\
 * FUNCTION: Get_MMIC_Secondary_Fault
 *===========================================================================
 * RETURN VALUE:
 *    CODED TRUE/CODE FALSE
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function returns the Secondary Clock Fault status by checking the corresponding FSM states for clock faults.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/
uint8_t Get_MMIC_Secondary_Fault(MMIC_Secondary_Fault_T SM_Error_flag)
{
   FuSa_Faults_Union_T *fusa_active_flt_ptr = Get_Mmic_Fusa_Active_Fault_Ptr();
   uint8_t err_status                       = CODED_FALSE;
   switch (SM_Error_flag)
   {
      case MMIC_Secondary_Clock_Fault:
         if (fusa_active_flt_ptr->fusa_fault_bits.sm_026_cpll_lock || fusa_active_flt_ptr->fusa_fault_bits.sm_027_syth_lock ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_028_spll_lock || fusa_active_flt_ptr->fusa_fault_bits.sm_029_clkcore_comp ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_030_clksys_comp)
         {
            err_status = CODED_TRUE;
         }
         break;
      case MMIC_Secondary_MCU_Fault:
         if (fusa_active_flt_ptr->fusa_fault_bits.sm_001_mcu_cpu_dcls || fusa_active_flt_ptr->fusa_fault_bits.sm_002_deprecated ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_003_mcu_ahb_parity ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_004_mcu_ahb_timeout ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_005_mcu_ahb_cdcmon ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_006_mcu_mailbox_overflow ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_007_mcu_mailbox_underflow ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_008_mcu_mailbox_parity ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_009_mcu_ssi_wcrc ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_010_mcu_ssi_rcrc || fusa_active_flt_ptr->fusa_fault_bits.sm_011_mcu_maf_crc ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_012_mcu_dma_red ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_013_mcu_frame_monitor)
         {
            err_status = CODED_TRUE;
         }
         break;
      case MMIC_Secondary_Register_Fault:
         if (fusa_active_flt_ptr->fusa_fault_bits.sm_014_regs_data_parity ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_015_regs_data_readback ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_016_regs_ctrl_redundancy)
         {
            err_status = CODED_TRUE;
         }
         break;
      case MMIC_Secondary_TX_RFBIST_Fault:
         if (fusa_active_flt_ptr->fusa_fault_bits.sm_080_tx_phaserot_rfgainbalmon ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_081_tx_phaserot_digitalmon ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_082_tx_relphasemon ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_085_tx_inc_powermon ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_086_tx_recphasemon ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_083_tx_relampmon)
         {
            err_status = CODED_TRUE;
         }
         break;
      case MMIC_Secondary_RX_RFBIST_Fault:
         if (fusa_active_flt_ptr->fusa_fault_bits.sm_072_rx_ampmon || fusa_active_flt_ptr->fusa_fault_bits.sm_073_rx_pissa_mon ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_074_rx_noisemon || fusa_active_flt_ptr->fusa_fault_bits.sm_075_rx_relampmon ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_076_rx_relphasemon ||
             fusa_active_flt_ptr->fusa_fault_bits.sm_077_rx_ifvga_freqmon)
         {
            err_status = CODED_TRUE;
         }
         break;
   }

   return err_status;
}

/*===========================================================================*\
  * FUNCTION: Compute_MMIC_On_Chip_Temperature
  *===========================================================================
  *===========================================================================
  * RETURN VALUE:
  * CAverage Temperature is returned
  *
  * PARAMETERS: void
  *
  * --------------------------------------------------------------------------
  * ABSTRACT:
  * Function to compute the Average Temperature based on
  * SMC Enable/Disable flag of each Tx/RX and Onchip modules
  * --------------------------------------------------------------------------
  * Requirements:
  * PDD:
  * --------------------------------------------------------------------------
  *
 \*===========================================================================*/

int16_t Compute_MMIC_On_Chip_Temperature(void)
{
   uint8_t i;
   uint8_t count    = 0U;
   int32_t temp     = 0;
   int16_t avg_temp = 0;

   uint8_t *rx_temp_sens_ptr   = &k_enable_temp_sensor_rx_smc[0];
   uint8_t *tx_temp_sens_ptr   = &k_enable_temp_sensor_tx_smc[0];
   uint8_t *quad_temp_sens_ptr = &k_enable_temp_sensor_pm_smc;

   const Temp_Sensor_Config_Entry_T sensors[NUMBER_OF_TEMP_SENSORS] = {
      {Get_Mmic_Temp_Tx0(), (uint8_t)(tx_temp_sens_ptr[0] & TEMP_SENSOR_ENABLE_BITMASK), false},    /* TX0                */
      {Get_Mmic_Temp_Tx1(), (uint8_t)(tx_temp_sens_ptr[1] & TEMP_SENSOR_ENABLE_BITMASK), false},    /* TX1                */
      {Get_Mmic_Temp_Tx2(), (uint8_t)(tx_temp_sens_ptr[2] & TEMP_SENSOR_ENABLE_BITMASK), false},    /* TX2                */
      {Get_Mmic_Temp_Tx3(), (uint8_t)(tx_temp_sens_ptr[3] & TEMP_SENSOR_ENABLE_BITMASK), false},    /* TX3                */
      {Get_Mmic_Temp_PVT(), (uint8_t)(rx_temp_sens_ptr[1] & TEMP_SENSOR_ENABLE_BITMASK), false},    /* PVT                */
      {Get_Mmic_Temp_PVT_TS(), (uint8_t)(rx_temp_sens_ptr[2] & TEMP_SENSOR_ENABLE_BITMASK), false}, /* PVT_TSENSE         */
      {Get_Mmic_Temp_Rx0(), (uint8_t)(rx_temp_sens_ptr[0] & TEMP_SENSOR_ENABLE_BITMASK), true},     /* RX0  - CW only     */
      {Get_Mmic_Temp_Quad(), (uint8_t)(quad_temp_sens_ptr[0] & TEMP_SENSOR_ENABLE_BITMASK), true},  /* QUAD - CW only     */
   };

   for (i = 0U; i < NUMBER_OF_TEMP_SENSORS; i++)
   {
      if (!sensors[i].cw_mode || CW_MODE_FLAG) /* Include sensor: always for normal sensors, only in CW mode for CW-only sensors */
      {
         count += sensors[i].enabled;
         temp += (int32_t)(sensors[i].enabled * sensors[i].temperature);
      }
   }

   if (count > 0U)
   {
      avg_temp = (int16_t)(temp / count);
   }
   return (avg_temp);
}
FuSa_Faults_Union_T *Get_Mmic_Fusa_Active_Fault_Ptr(void)
{
   return (&MMIC_Fusa_Active_Fault);
}

FuSa_Faults_Union_T *Get_Mmic_Fusa_Backup_Fault_Ptr(void)
{
   return (&MMIC_Fusa_Backup_Fault);
}
/*===========================================================================*\
 * FUNCTION: Populate_Fusa_Faults_In_Debug_Stream
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    Debug_Stream_T *debug_stream_ptr - Pointer to the debug stream to populate.
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * Copies the backup FuSa fault states into the provided
 * debug stream structure. Uses getter accessors to avoid direct global
 * variable references at the call site.
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Populate_Fusa_Faults_In_Debug_Stream(Debug_Stream_T *debug_stream_ptr)
{
   const FuSa_Faults_Union_T *fusa_backup_flt_ptr = Get_Mmic_Fusa_Backup_Fault_Ptr();
   uint32_t backup_fault_copy_len = (uint32_t)sizeof(debug_stream_ptr->MMIC_fusa_fault_status.mmic_fusa_backup_fault);

   if (backup_fault_copy_len > (uint32_t)sizeof(FuSa_Faults_Union_T))
   {
      backup_fault_copy_len = (uint32_t)sizeof(FuSa_Faults_Union_T);
   }
   /* Serialize backup FuSa fault bits into debug stream payload. */
   (void)memcpy(debug_stream_ptr->MMIC_fusa_fault_status.mmic_fusa_backup_fault, (const void *)fusa_backup_flt_ptr,
                backup_fault_copy_len);
}
/*===========================================================================*\
 * FUNCTION: Update_Mars_Reg_From_OTP
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 *
 * --------------------------------------------------------------------------
 * ABSTRACT:
 * This function updates the MARS registers with values from OTP based on the hardware version.
 * --------------------------------------------------------------------------
 *\*===========================================================================*/

void Update_Mars_Reg_From_OTP(void)
{
   bool api_fail = Is_MMIC_Api_Fail(API_Ret_Val, __func__);
   if (Mars_OTP_Version == MARS_OTP_VERSION_V10)
   {
      if (!api_fail)
      {
         API_Ret_Val = Mars_Write_Register_Value(MARS_F_CORE_BANK_LODST_ASTX_I, 14U);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_write_register fail\n");
      }
      if (!api_fail)
      {
         API_Ret_Val = Mars_Write_Register_Value(MARS_F_CORE_BANK_LODST_ASRX_I, 14U);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_write_register fail\n");
      }
      if (!api_fail)
      {
         API_Ret_Val = Mars_Write_Register_Value(MARS_F_CORE_BANK_LODST_ASTXRX_I, 14U);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_write_register fail\n");
      }
      if (!api_fail)
      {
         API_Ret_Val = Mars_Write_Register_Value(MARS_F_CORE_BANK_TX_PR_CS_TB, 7U);
         api_fail    = Is_MMIC_Api_Fail(API_Ret_Val, "mars_write_register fail\n");
      }
   }
}
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 * Date         userid    (Description on following lines: SCR #, etc.)
 * ----------- --------  ----------------------------------------------------
 * 17-Jun-2024  qjgws1   Initial version for Spec v1
 * 22-Apr-2025  djdgwr   EPB-3706: [Gen8] [MMIC][SWE1_SWE3][R2.0]-Implemented the Low Temperature Fault changes.
 * 29-May-2025  ftoobg   EPB-3757: [Gen8][SWE3][R2.0]Monitor RFE PLL lock status, report lock fault when detected
 * 08-Jul-2025  qjgws1   EPB-3940: Add more custom register writes based on feedback from Systems and bring the tiger team
                                   branches to dev
 * 17-Jul-2025  ftoobg   EPB-3903: [Gen8][SWE3][R3.0] Use Case: Request Safe Start up: Transceiver and peripheral initialization
 and failure
 * 21-Jul-2025  qjgws1   EPB-3944: Bring in Mars reset mechanism from tiger team branch temporarily
 * 22-Jul-2025  jjrfgz   EPB-3984: TICS Coding Standard Improvement
 * 29-Jul-2025  qjgws1   EPB-3943: Workaround for core freeze upon reset during init
 * 12-Aug-2025  qjgws1   EPB-4002: Removing the work around for core freeze issue since actual root cause was found
 * 3-Sep-2025   njsfs0   EPB-2029: F1 9F command implementation
 * 07-Oct-2025  qjgws1   EPB-4123: Bring changes for Debug Logging and ADC unit fixes into dev
 * 24-Sep-2025  ftoobg   EPB-3939: [Gen8][SWE3][R3.0] Use Case: Analog safety monitors and it's linkage to sensor dead fault
 * 01-Dec-2025  qjgws1   EPB-4240: [Gen8]: Fix for the mars resets being observed(the sft pin is not mature enough)
 * 04-Dec-2025  qjgws1   EPB-4239: MAF V0.18 for A Sample  and MAF 10.1.2.1 for B sample Integration
 * 08-Dec-2025  qjgws1   EPB-4239: MAF v10.2.2.1 For B Sample Integration
 * 18-Dec-2025  BC       EPB-4291: merge Gen8_A2HW_Bringup to dev for A2.3.0 HW ChandraB0 MarsA0/B1
 *                                 Some adaptations needed as diagnostic approach has changed with MAF v10.2.2.1 and MAF
 v10.2.1.2
 *                                 TODO_CHANDRA_B0: Ex: mmic_analog_bist_status, sft_mon, temp and other diag
 * 29-Dec-2025  ftoobg   EPB-4264: [Gen8][SWE3]MARS safety: API return value handling
 * 28-Nov-2025  ftoobg   EPB-4128: [Gen8][SWE3] Implement Mars Safety: MMIC Safety Critical Errors Handling
 * 14-Jan-2026  qjgws1   EPB-4312: [Gen8][SWE3] Integrate MARS FWv10.2.3.3 for B Sample Mars
 * 20-Jan-2026  ftoobg   EPB-3952: [Gen8][SWE3] Implement Mars Safety: MMIC Safety Critical Errors Handling
 * 27-Jan-2026  qjgws1   EPB-4327: [Gen8][SWE3] Fix for stale temperature readings in MMIC stream
 * 29-Jan-2026  ftoobg   EPB-4354: [GEN8][CRD][SWE3] Provide Timestamp for Start of Acquisition
 * 06-Feb-2026  njsfs0   EPB-4320: [GEN8] Temperature data over XCP.
 * 10-Feb-2026  qjgws1   EPB-4374: [Gen8][SWE3]MAF 10.3.0.2  and API 2.0.0 Integration
 * 12-Feb-2026  qjgws1   EPB-4377: [Gen8][SWE3] Fetching available config values from SMC V25.
 * 12-Feb-2026  djdgwr   EPB-4387: Added Function Config(alias API_LOOK_CONFIGURATION FAIL) FIT to inject faults using XCP F1 12
 * 18-Feb-2026  djdgwr   EPB-4459: [GEN8][SWE3] Implement & Integration of MIPI Diagnostic function

 * 25-Feb-2026  qjgws1   EPB-4373: MAF 10.3.1.1 and workarounds for the issue with MAF BUSY
 * 23-Feb-2026  ftoobg   EPB-4461: [GNE8]Bring Radar Control SM changes similar to GEN7_V2/GEN7_V1 into GEN8 variant
 * 23-Feb-2026  ftoobg   EPB-4410 [Gen8][SWE6] Mars Safety: MMIC Safety Critical Errors Handling
 * 03-Mar-2026  qjgws1   EPB-4373: [GEN8][SWE3] Integrated the API 2.1.0 that is compatible with MAF 10.3.1.1
 * 09-Mar-2026  djdgwr   EPB-4391: [GEN8][SWE3]-Implementation]-Common Function for Fault Injection(removed the FIT cases inside
 the code)
 * 16-Mar-2026  ftoobg   EPB-4434: [Gen8]Function names as per v2 in Gen8
 * 19-Mar-2026  djdgwr   EPB-4462: [GEN8][SWE3]-dd_mmic.c file code clean up.
 * 27-Mar-2026  qjgws1   EPB-4609: [GEN8][SWE3] - MAF 10.3.1.4 and API 2.2.0 API integration and updated diag mem layout
 * 15-Apr-2026  djdgwr   EPB-4643: [Gen8][SWE3][R6.0]- Fix Level 1 to 4 warnings in dd_mmic.c and F1 12 Cmd Improvements.
 * 29-Apr-2026  jjrfgz   EPB-4547: [Gen8][SWE3][R6.0]Integration of Exec Spec changes into Embedded Software - ZHV Implementation
 * 06-May-2026  jjrfgz   EPB-4102:[Gen8]SMC ZHV BIST config variables updates for mars_configure_bist
 * 06-May-2026  njsfs0   EPB-4686: [GEN8][SWE3][R6.0] -Data Acq threshould changes and related code changes
 * 14-May-2026  ftoobg   EPB-4419 [Gen8] [SWE3] Use Case: Monitor and report RFE MCU related faults
 *
 * 07-May-2026  djdgwr   EPB-4662: [Gen8] [SWE_3] [R6.0] -(F1 9B) Phase Rotator Calibration In Manufacturing -Implementation
 * 12-May-2026  ftoobg   EPB-4685 [Gen8][SWE3][R6.0]update average temperature similar to GEN7_V2
 * 29-May-2026  ftoobg   EPB-4552 [Gen8] [SWE3]MAF integration
 * 02-June-2026 jjrfgz   EPB-4186 [Gen8] [SWE1][R6.0](F1 99) Transceiver Calibration In Manufacturing
 * 05-June-2026 JZRX03   EPB-4590 MARS Config BIST array change
 * 11-June-2026 jjrfgz   EPB-4692 Mapping BIST SMs to Active Faults
 * 16-June-2026  jjrfgz  EPB-4614 (F1 99) BIST Parametric data get function updates
 * 12-June-2026 ftoobg   EPB-4705 [Gen8][SWE3][R7]Safety Mechanism implementation in the code as per v6.0
 * 19-Jun-2026  ftoobg  EPB-4722: [Gen8][SWE1] Update of Register based on OTP
 * 14-June-2026 jjrfgz  EPB-4575: [Gen8]TX & RX BIST Faults additional SMs added ,FIT updated
 * 09-Jul-2026  ftoobg  EPB-4770 [Gen8] [R7][SWE3] Use Case: Thermal management and Fault Handling- New strategy (MARS)
 * 16-Jul-2026  njsfs0  EPB-4721 [Gen8]Maf integration 3.5.3
 * 17-Jul-2026 jjrfgz  EPB-4831 [Gen8] Function added to Populate_Fusa_Faults_In_Debug_Stream
 * 21-Jul-2026  jjrfgz  EPB-4869: [Gen8][SWE3][R6.1] OVLD register Write updates in Look Configure
 * 17-Aug-2026 njsfs0  EPB-4815 [Gen8] Chirp Gen slope hardcode with SMC for AL.
 * 18-Aug-2026 jjrfgz  EPB-4887 [Gen8]2 Stage ZHV Calibration updates
 * 25-Aug-2026 ftoobg  EPB-4779 [Gen8]Implement Generic MARS Register Read/Write Logic Within Look Trigger
 * 26-Aug-2026 qjgws1  EPB-4881 [Gen8][SWE3] Maf upload mechanism changed to be called from mcal_init to prevent flash read
 failures during init
 * 26-Aug-2026 jjrfgz EPB-4901[Gen8]Removal of Active Fusa Fault from Debug stream and CRC calculation function of ZHV Array
 *===========================================================================*/
