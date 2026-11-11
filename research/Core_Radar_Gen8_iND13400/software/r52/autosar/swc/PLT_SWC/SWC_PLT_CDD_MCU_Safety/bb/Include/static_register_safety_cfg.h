#ifndef STATIC_REGISTER_SAFETY_CFG_H
#define STATIC_REGISTER_SAFETY_CFG_H
/*===========================================================================*\
 * FILE: static_register_safety_cfg.h
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
 *   This file contains the header files for Functional Safety Configuration.
 *
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
#include "Std_Types.h"

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/
#define MAX_REG_INDEX_BYTES    ((uint8_t)35)
#define EXPECTED_CRC_VALUE_A0  ((uint32_t)0xA9796AA0)
#define EXPECTED_CRC_VALUE_EDU ((uint32_t)0xAD49DB7A)

/* Helper macro to cast register addresses */
#define REG_PTR(addr) ((const uint32_t *)(uintptr_t)(addr))

/*===========================================================================*\
 * Register Description X-Macro
\*===========================================================================*/
/*Register Description that has been configured for CRC calculation*/
/*If there is any addition or removal of registers from this list please update the macro MAX_NO_REGISTER value
 * accordingly*/

#define REGISTERS_DESCRIPTION_LIST(DCS_X)                                                                                         \
   DCS_X(PWM_CFG)                                                                                                                 \
   DCS_X(ACFCTRL)                                                                                                                 \
   DCS_X(INTE)                                                                                                                    \
   DCS_X(FD_TIME)                                                                                                                 \
   DCS_X(ACFM_0)                                                                                                                  \
   DCS_X(ACFM_1)                                                                                                                  \
   DCS_X(ACFM_2)                                                                                                                  \
   DCS_X(ACFM_3)                                                                                                                  \
   DCS_X(ACFC_0)                                                                                                                  \
   DCS_X(ACFC_1)                                                                                                                  \
   DCS_X(ACFC_2)                                                                                                                  \
   DCS_X(ACFC_3)                                                                                                                  \
   DCS_X(AC_TIME)                                                                                                                 \
   DCS_X(LATENCY_CTRL)                                                                                                            \
   DCS_X(MACSEC_IP_CONTROL)                                                                                                       \
   DCS_X(MACSEC_CFG_MIN_IPG)                                                                                                      \
   DCS_X(MACSEC_IP_VLAN)                                                                                                          \
   DCS_X(RLS_CNT_SETUP_VALUE)                                                                                                     \
   DCS_X(IRQ_GLBL_EN)                                                                                                             \
   DCS_X(DMA_CH1_INTERRUPT_ENABLE)                                                                                                \
   DCS_X(DMA_CH1_RX_CONTROL)                                                                                                      \
   DCS_X(DMA_CH1_RX_CONTROL2)                                                                                                     \
   DCS_X(DMA_CH1_TXDESC_RING_LENGTH)                                                                                              \
   DCS_X(DMA_CH1_TX_CONTROL)                                                                                                      \
   DCS_X(DMA_CH1_CONTROL)                                                                                                         \
   DCS_X(DMA_CH0_INTERRUPT_ENABLE)                                                                                                \
   DCS_X(DMA_CH0_RX_CONTROL2)                                                                                                     \
   DCS_X(DMA_CH0_TXDESC_RING_LENGTH)                                                                                              \
   DCS_X(DMA_CH0_RX_CONTROL)                                                                                                      \
   DCS_X(DMA_CH0_TX_CONTROL)                                                                                                      \
   DCS_X(DMA_CH0_CONTROL)                                                                                                         \
   DCS_X(DMA_ECC_INTERRUPT_ENABLE)                                                                                                \
   DCS_X(GPIO_INTEN)                                                                                                              \
   DCS_X(GPIO_INTMASK)                                                                                                            \
   DCS_X(GPIO_SWPORTA_DDR)                                                                                                        \
   DCS_X(GPIO_INTTYPE_LEVEL)                                                                                                      \
   DCS_X(PIO_INT_POLARITY)                                                                                                        \
   DCS_X(GPIO_INT_BOTHEDGE)                                                                                                       \
   DCS_X(IC_INTR_MASK)                                                                                                            \
   DCS_X(IC_CON)                                                                                                                  \
   DCS_X(IC_SAR)                                                                                                                  \
   DCS_X(IC_TX_TL)                                                                                                                \
   DCS_X(IC_RX_TL)                                                                                                                \
   DCS_X(IC_ENABLE)                                                                                                               \
   DCS_X(IC_SDA_HOLD)                                                                                                             \
   DCS_X(IC_DMA_CR)                                                                                                               \
   DCS_X(IC_DMA_TDLR)                                                                                                             \
   DCS_X(IC_DMA_RDLR)                                                                                                             \
   DCS_X(IC_SDA_SETUP)                                                                                                            \
   DCS_X(IC_SMBUS_CLK_LOW_SEXT)                                                                                                   \
   DCS_X(IC_SMBUS_CLK_LOW_MEXT)                                                                                                   \
   DCS_X(IC_SMBUS_INTR_MASK)                                                                                                      \
   DCS_X(IC_SAR2)                                                                                                                 \
   DCS_X(CH1_AXI_QOSREG)                                                                                                          \
   DCS_X(AXI_ARQOS1)                                                                                                              \
   DCS_X(CH2_AXI_QOSREG)                                                                                                          \
   DCS_X(AXI_ARQOS2)                                                                                                              \
   DCS_X(CH3_AXI_QOSREG)                                                                                                          \
   DCS_X(AXI_ARQOS3)                                                                                                              \
   DCS_X(CH4_AXI_QOSREG)                                                                                                          \
   DCS_X(AXI_ARQOS4)                                                                                                              \
   DCS_X(CH1_INTSIGNAL_ENABLEREG1)                                                                                                \
   DCS_X(CH1_INTSIGNAL_ENABLEREG2)                                                                                                \
   DCS_X(CH2_INTSIGNAL_ENABLEREG1)                                                                                                \
   DCS_X(CH2_INTSIGNAL_ENABLEREG2)                                                                                                \
   DCS_X(CH3_INTSIGNAL_ENABLEREG1)                                                                                                \
   DCS_X(CH3_INTSIGNAL_ENABLEREG2)                                                                                                \
   DCS_X(CH4_INTSIGNAL_ENABLEREG1)                                                                                                \
   DCS_X(CH4_INTSIGNAL_ENABLEREG2)                                                                                                \
   DCS_X(DMAC_CFGREG)                                                                                                             \
   DCS_X(DMAC_CFGREG_EN)                                                                                                          \
   DCS_X(DMAC_LOWPOWER_CFGREG)                                                                                                    \
   DCS_X(DMAC_LOWPOWER_CFGREG1)                                                                                                   \
   DCS_X(CH1_SAR1)                                                                                                                \
   DCS_X(CH1_SAR2)                                                                                                                \
   DCS_X(CH2_SAR1)                                                                                                                \
   DCS_X(CH2_SAR2)                                                                                                                \
   DCS_X(CH3_SAR1)                                                                                                                \
   DCS_X(CH3_SAR2)                                                                                                                \
   DCS_X(CH4_SAR1)                                                                                                                \
   DCS_X(CH4_SAR2)                                                                                                                \
   DCS_X(CH1_DAR1)                                                                                                                \
   DCS_X(CH1_DAR2)                                                                                                                \
   DCS_X(CH2_DAR1)                                                                                                                \
   DCS_X(CH2_DAR2)                                                                                                                \
   DCS_X(CH3_DAR1)                                                                                                                \
   DCS_X(CH3_DAR2)                                                                                                                \
   DCS_X(CH4_DAR1)                                                                                                                \
   DCS_X(CH4_DAR2)                                                                                                                \
   DCS_X(CH1_BLOCK_TS1)                                                                                                           \
   DCS_X(CH1_BLOCK_TS2)                                                                                                           \
   DCS_X(CH2_BLOCK_TS1)                                                                                                           \
   DCS_X(CH2_BLOCK_TS2)                                                                                                           \
   DCS_X(CH3_BLOCK_TS1)                                                                                                           \
   DCS_X(CH3_BLOCK_TS2)                                                                                                           \
   DCS_X(CH4_BLOCK_TS1)                                                                                                           \
   DCS_X(CH4_BLOCK_TS2)                                                                                                           \
   DCS_X(CH1_CTL1)                                                                                                                \
   DCS_X(CH1_CTL2)                                                                                                                \
   DCS_X(CH2_CTL1)                                                                                                                \
   DCS_X(CH2_CTL2)                                                                                                                \
   DCS_X(CH3_CTL1)                                                                                                                \
   DCS_X(CH3_CTL2)                                                                                                                \
   DCS_X(CH4_CTL1)                                                                                                                \
   DCS_X(CH4_CTL2)                                                                                                                \
   DCS_X(CH1_CFG1)                                                                                                                \
   DCS_X(CH1_CFG2)                                                                                                                \
   DCS_X(CH2_CFG1)                                                                                                                \
   DCS_X(CH2_CFG2)                                                                                                                \
   DCS_X(CH3_CFG1)                                                                                                                \
   DCS_X(CH3_CFG2)                                                                                                                \
   DCS_X(CH4_CFG1)                                                                                                                \
   DCS_X(CH4_CFG2)                                                                                                                \
   /* DCS_X(IMR) */    /* Changing in runtime upon mars_reset */                                                                  \
   /* DCS_X(CTRLR0) */ /* Changing in runtime for EDU board */                                                                    \
   DCS_X(MWCR)                                                                                                                    \
   /*DCS_X(BAUDR)   */                                                                                                            \
   DCS_X(TXFTLR)                                                                                                                  \
   DCS_X(RXFTLR)                                                                                                                  \
   DCS_X(AXIAWLEN)                                                                                                                \
   DCS_X(AXIARLEN)                                                                                                                \
   DCS_X(RX_SAMPLE_DELAY)                                                                                                         \
   /* DCS_X(SPI_CTRLR0) */ /* Changing in runtime for EDU board */                                                                \
   DCS_X(SPI_CTRLR1)                                                                                                              \
   DCS_X(TIMER1CONTROLREG)                                                                                                        \
   DCS_X(TIMER2CONTROLREG)                                                                                                        \
   DCS_X(TIMER3CONTROLREG)                                                                                                        \
   DCS_X(WDT_CR)                                                                                                                  \
   DCS_X(CLK_TOP_CTRL)                                                                                                            \
   DCS_X(BOR_0P8_TRIM)                                                                                                            \
   DCS_X(BOR_1P8_TRIM)                                                                                                            \
   DCS_X(RESET_LOCKOUT)                                                                                                           \
   DCS_X(ADC_CTRL)                                                                                                                \
   DCS_X(GEN_CONFIG)                                                                                                              \
   DCS_X(CH0_CONFIG1)                                                                                                             \
   DCS_X(CH0_CONFIG3)                                                                                                             \
   DCS_X(CH1_CONFIG1)                                                                                                             \
   DCS_X(CH1_CONFIG3)                                                                                                             \
   DCS_X(CH2_CONFIG1)                                                                                                             \
   DCS_X(CH3_CONFIG1)                                                                                                             \
   DCS_X(CH4_CONFIG1)                                                                                                             \
   DCS_X(CH5_CONFIG1)                                                                                                             \
   DCS_X(CH6_CONFIG1)                                                                                                             \
   DCS_X(CH7_CONFIG1)                                                                                                             \
   DCS_X(CH8_CONFIG1)                                                                                                             \
   DCS_X(CH9_CONFIG1)                                                                                                             \
   DCS_X(CH2_CONFIG3)                                                                                                             \
   DCS_X(CH3_CONFIG3)                                                                                                             \
   DCS_X(CH4_CONFIG3)                                                                                                             \
   DCS_X(CH5_CONFIG3)                                                                                                             \
   DCS_X(CH6_CONFIG3)                                                                                                             \
   DCS_X(CH7_CONFIG3)                                                                                                             \
   DCS_X(CH8_CONFIG3)                                                                                                             \
   /* DCS_X(CH9_CONFIG3) */ /*This reg is changing sporadically after 54D ADC driver integartion in runtime*/                     \
   DCS_X(GPIO_00)                                                                                                                 \
   DCS_X(GPIO_01)                                                                                                                 \
   DCS_X(GPIO_02)                                                                                                                 \
   DCS_X(GPIO_03)                                                                                                                 \
   DCS_X(GPIO_04)                                                                                                                 \
   DCS_X(GPIO_05)                                                                                                                 \
   DCS_X(GPIO_06)                                                                                                                 \
   DCS_X(GPIO_07)                                                                                                                 \
   DCS_X(GPIO_08)                                                                                                                 \
   DCS_X(GPIO_09)                                                                                                                 \
   DCS_X(GPIO_10)                                                                                                                 \
   DCS_X(GPIO_11)                                                                                                                 \
   DCS_X(GPIO_12)                                                                                                                 \
   DCS_X(GPIO_13)                                                                                                                 \
   /* DCS_X(GPIO_14) */ /* Changing in runtime for EDU board */                                                                   \
   /* DCS_X(GPIO_15) */ /* Changing in runtime for EDU board */                                                                   \
   DCS_X(GPIO_16)                                                                                                                 \
   DCS_X(GPIO_17)                                                                                                                 \
   DCS_X(GPIO_18)                                                                                                                 \
   DCS_X(GPIO_19)                                                                                                                 \
   DCS_X(GPIO_20)                                                                                                                 \
   DCS_X(GPIO_21)                                                                                                                 \
   DCS_X(FLASH_QSPI_D0)                                                                                                           \
   DCS_X(FLASH_QSPI_D1)                                                                                                           \
   DCS_X(FLASH_QSPI_D2)                                                                                                           \
   DCS_X(FLASH_QSPI_D3)                                                                                                           \
   DCS_X(FLASH_QSPI_CLK)                                                                                                          \
   DCS_X(FLASH_QSPI_CSN)                                                                                                          \
   DCS_X(MM_QSPI_CLK)                                                                                                             \
   DCS_X(MM_QSPI_CSN)                                                                                                             \
   DCS_X(MM_QSPI_D0)                                                                                                              \
   DCS_X(MM_QSPI_D1)                                                                                                              \
   DCS_X(MM_QSPI_D2)                                                                                                              \
   DCS_X(MM_QSPI_D3)                                                                                                              \
   DCS_X(MM_FRAME_SOT)                                                                                                            \
   DCS_X(MM_IRQ)                                                                                                                  \
   /* DCS_X(CTRL) */       /* updating runtime in standalone mode */                                                              \
   /* DCS_X(MIPI_CTRL0) */ /* updating runtime in standalone mode */                                                              \
   /* DCS_X(MIPI_CTRL1) */ /* updating runtime in standalone mode */                                                              \
   DCS_X(FUSA_IRQ0_EN)                                                                                                            \
   DCS_X(FUSA_IRQ1_EN)                                                                                                            \
   DCS_X(FUSA_IRQ2_EN)                                                                                                            \
   /* DCS_X(DC_ESTIMATION_CONTROL_0_CH0) */ /* updating runtime in standalone mode */                                             \
   DCS_X(PWM0_CSR)                                                                                                                \
   DCS_X(PWM0_SLOPE_STEP)                                                                                                         \
   DCS_X(PWM0_DITHER_CTRL)                                                                                                        \
   /* DCS_X(PWM0_NOMINAL_PERIOD) */ /* Chandra B0 not supported */                                                                \
   DCS_X(PWM0_MIN_PERIOD)                                                                                                         \
   DCS_X(PWM0_MAX_PERIOD)                                                                                                         \
   DCS_X(PWM1_CSR)                                                                                                                \
   DCS_X(PWM1_SLOPE_STEP)                                                                                                         \
   DCS_X(PWM1_DITHER_CTRL)                                                                                                        \
   /* DCS_X(PWM1_NOMINAL_PERIOD) */ /* Chandra B0 not supported */                                                                \
   DCS_X(PWM1_MIN_PERIOD)                                                                                                         \
   DCS_X(PWM1_MAX_PERIOD)                                                                                                         \
   DCS_X(PWM2_CSR)                                                                                                                \
   DCS_X(PWM2_SLOPE_STEP)                                                                                                         \
   DCS_X(PWM2_DITHER_CTRL)                                                                                                        \
   DCS_X(PWM2_NOMINAL_PERIOD)                                                                                                     \
   DCS_X(PWM2_MIN_PERIOD)                                                                                                         \
   DCS_X(PWM2_MAX_PERIOD)                                                                                                         \
   DCS_X(PWM3_CSR)                                                                                                                \
   DCS_X(PWM3_SLOPE_STEP)                                                                                                         \
   DCS_X(PWM3_DITHER_CTRL)                                                                                                        \
   DCS_X(PWM3_NOMINAL_PERIOD)                                                                                                     \
   DCS_X(PWM3_MIN_PERIOD)                                                                                                         \
   DCS_X(PWM3_MAX_PERIOD)                                                                                                         \
   DCS_X(LBIST_MEM_MISC_CTRL0)                                                                                                    \
   DCS_X(LBIST_MEM_MISC_CTRL1)                                                                                                    \
   DCS_X(PVT0_CTRL0)                                                                                                              \
   DCS_X(PVT0_CTRL1)                                                                                                              \
   DCS_X(PVT0_CTRL2)                                                                                                              \
   DCS_X(PVT0_CTRL3)                                                                                                              \
   DCS_X(PVT0_CTRL4)                                                                                                              \
   DCS_X(PVT1_CTRL0)                                                                                                              \
   DCS_X(PVT1_CTRL1)                                                                                                              \
   DCS_X(PVT1_CTRL2)                                                                                                              \
   DCS_X(PVT1_CTRL3)                                                                                                              \
   DCS_X(PVT1_CTRL4)                                                                                                              \
   DCS_X(PVT0_TO_CTRL0)                                                                                                           \
   DCS_X(PVT1_TO_CTRL0)                                                                                                           \
   DCS_X(PVT0_BYP_CTRL)                                                                                                           \
   DCS_X(PVT0_IRQ_CTRL)                                                                                                           \
   DCS_X(PVT1_IRQ_CTRL)                                                                                                           \
   DCS_X(MMINTF_SIG_CTRL)                                                                                                         \
   DCS_X(PMIC_FAULTB_CTRL)                                                                                                        \
   DCS_X(MISC_CTRL)                                                                                                               \
   DCS_X(SERDES_MISC_CTRL)                                                                                                        \
   DCS_X(MEM_CTRL)                                                                                                                \
   DCS_X(MEM_INIT_CTRL)                                                                                                           \
   /* DCS_X(WDT_TOP_CTRL) */    /* Condition to be added later for debug mode */                                                  \
   /* DCS_X(TIMERS_TOP_CTRL) */ /* Condition to be added later for debug mode */                                                  \
   DCS_X(HSM_SRAM_CTRL)                                                                                                           \
   DCS_X(HSM_MISC_CTRL)                                                                                                           \
   /* DCS_X(SPI_RXD_CTRL) */ /* temporarily disabling because of registers update delay */                                        \
   DCS_X(PWM_TOP_CTRL0)                                                                                                           \
   DCS_X(PWM_TOP_CTRL1)                                                                                                           \
   DCS_X(SERDES_IRQ_ENA)                                                                                                          \
   DCS_X(TRNG_CHAR_CTRL)                                                                                                          \
   DCS_X(TRNG_VAL_CTRL)                                                                                                           \
   DCS_X(SEC_CNT_CTRL)                                                                                                            \
   DCS_X(AMEM_IRQ_ENA)                                                                                                            \
   DCS_X(ETHERNET_MCGR_CTRL)                                                                                                      \
   DCS_X(NOC_MISC_CTRL)                                                                                                           \
   DCS_X(R52_CEE_LIM_CTRL1)                                                                                                       \
   DCS_X(R52_CEE_LIM_CTRL2)                                                                                                       \
   DCS_X(R52_CEE_LIM_CTRL3)                                                                                                       \
   /* DCS_X(R52_CEE_SNAP_CTRL) */ /* This register should be removed from crc protection refer WI-405616 */                       \
   DCS_X(R52_CEE_IRQ_ENA_CTRL)                                                                                                    \
   DCS_X(MCE_LIM_CTRL0)                                                                                                           \
   DCS_X(MCE_SNAP_CTRL)                                                                                                           \
   DCS_X(MCE_IRQ_ENA_CTRL)                                                                                                        \
   DCS_X(PORT0_MISC_CTRL0)                                                                                                        \
   DCS_X(PORT1_MISC_CTRL0)                                                                                                        \
   DCS_X(PORT0_ECC_CTRL0)                                                                                                         \
   DCS_X(PORT1_ECC_CTRL0)                                                                                                         \
   DCS_X(PORT0_MODE_CTRL0)                                                                                                        \
   /* DCS_X(PORT1_MODE_CTRL0) */ /* TODO: value Changing for A0 ADC units with RDI MIPI Splitter connection */                    \
   DCS_X(PORT0_TRNP_CTRL0)                                                                                                        \
   DCS_X(PORT1_TRNP_CTRL0)                                                                                                        \
   DCS_X(IRQ_ENA_CTRL0)                                                                                                           \
   DCS_X(PORT0_RAM_CTRL0)                                                                                                         \
   DCS_X(PORT1_RAM_CTRL0)                                                                                                         \
   DCS_X(FCRU_CTRL_00)                                                                                                            \
   DCS_X(FCRU_CTRL_01)                                                                                                            \
   DCS_X(FCRU_CTRL_02)                                                                                                            \
   DCS_X(FCRU_CTRL_03)                                                                                                            \
   DCS_X(FCRU_CTRL_08)                                                                                                            \
   DCS_X(FCRU_CTRL_09)                                                                                                            \
   DCS_X(FCRU_CTRL_10)                                                                                                            \
   DCS_X(ETHER_CTRL)

/*===========================================================================*\
 * Helper Macros for Register List Generation
\*===========================================================================*/
#define REG_DESC_PTR(reg)  REG_PTR(reg),
#define REG_DESC_NAME(reg) #reg,
#define REG_DESC_ENUM(reg) REG_##reg,

/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
typedef enum Static_Registers_Tag
{
   REGISTERS_DESCRIPTION_LIST(REG_DESC_ENUM) REG_STATIC_MAX
} Static_Registers_T;

#endif /*STATIC_REGISTER_SAFETY_CFG_H*/
