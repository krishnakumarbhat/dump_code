#ifndef STATIC_REGISTER_SAFETY_H
#define STATIC_REGISTER_SAFETY_H
/*===========================================================================*\
 * FILE: static_register_safety.h
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
 *   This file contains the header files of static register safety mechanisum functions for Functional Safety Configuration.
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
#include "Std_Types.h"

/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "reuse.h"

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*\
    * Exported Preprocessor #define Constants
\*===========================================================================*/
/*Define Static register addresses -  Start*/
/*Project Static Register list can be added here */
/*Platform Register list starts here. Do Not Modify Platform Register list */
/*CAN0 */
#define PWM_CFG (0x919310ACU)
#define ACFM_0  (0x91930058U)
#define ACFM_1  (0x9193005CU)
#define ACFM_2  (0x91930060U)
#define ACFM_3  (0x91930064U)
#define ACFC_0  (0x91930048U)
#define ACFC_1  (0x9193004CU)
#define ACFC_2  (0x91930050U)
#define ACFC_3  (0x91930054U)
#define ACFCTRL (0x91930044U)
#define INTE    (0x91930018U)
#define FD_TIME (0x91930008U)
#define AC_TIME (0x91930004U)

/* Eth MAC */
#define LATENCY_CTRL               (0x8A002020)
#define MACSEC_IP_CONTROL          (0x8A006008)
#define MACSEC_CFG_MIN_IPG         (0x8A006010)
#define MACSEC_IP_VLAN             (0x8A006014)
#define RLS_CNT_SETUP_VALUE        (0x8A006040)
#define IRQ_GLBL_EN                (0x8A007000)
#define DMA_CH1_INTERRUPT_ENABLE   (0x8A0011B4)
#define DMA_CH1_RX_CONTROL         (0x8A001188)
#define DMA_CH1_RX_CONTROL2        (0x8A0011B0)
#define DMA_CH1_TXDESC_RING_LENGTH (0x8A0011AC)
#define DMA_CH1_TX_CONTROL         (0x8A001184)
#define DMA_CH1_CONTROL            (0x8A001180)
#define DMA_CH0_INTERRUPT_ENABLE   (0x8A001134)
#define DMA_CH0_RX_CONTROL2        (0x8A001130)
#define DMA_CH0_TXDESC_RING_LENGTH (0x8A00112C)
#define DMA_CH0_RX_CONTROL         (0x8A001108)
#define DMA_CH0_TX_CONTROL         (0x8A001104)
#define DMA_CH0_CONTROL            (0x8A001100)
#define DMA_ECC_INTERRUPT_ENABLE   (0x8A001084)

/* GPIO CTRL */
#define GPIO_INTEN         (0x91925030)
#define GPIO_INTMASK       (0x91925034)
#define GPIO_SWPORTA_DDR   (0x91925004)
#define GPIO_INTTYPE_LEVEL (0x91925038)
#define PIO_INT_POLARITY   (0x9192503C)
#define GPIO_INT_BOTHEDGE  (0x91925068)

/* I2C */
#define IC_INTR_MASK          (0x91920030)
#define IC_CON                (0x91920000)
#define IC_TAR                (0x91920004)
#define IC_SAR                (0x91920008)
#define IC_TX_TL              (0x9192003C)
#define IC_RX_TL              (0x91920038)
#define IC_ENABLE             (0x9192006C)
#define IC_SDA_HOLD           (0x9192007C)
#define IC_DMA_CR             (0x91920088)
#define IC_DMA_TDLR           (0x9192008C)
#define IC_DMA_RDLR           (0x91920090)
#define IC_SDA_SETUP          (0x91920094)
#define IC_SMBUS_CLK_LOW_SEXT (0x919200BC)
#define IC_SMBUS_CLK_LOW_MEXT (0x919200C0)
#define IC_SMBUS_INTR_MASK    (0x919200CC)
#define IC_SAR2               (0x91920100)

/* MC DMA */
#define CH1_AXI_QOSREG           (0x91400158)
#define AXI_ARQOS1               (0x9140015C)
#define CH2_AXI_QOSREG           (0x91400258)
#define AXI_ARQOS2               (0x9140025C)
#define CH3_AXI_QOSREG           (0x91400358)
#define AXI_ARQOS3               (0x9140035C)
#define CH4_AXI_QOSREG           (0x91400458)
#define AXI_ARQOS4               (0x9140045C)
#define CH1_INTSIGNAL_ENABLEREG1 (0x91400190)
#define CH1_INTSIGNAL_ENABLEREG2 (0x91400194)
#define CH2_INTSIGNAL_ENABLEREG1 (0x91400290)
#define CH2_INTSIGNAL_ENABLEREG2 (0x91400294)
#define CH3_INTSIGNAL_ENABLEREG1 (0x91400390)
#define CH3_INTSIGNAL_ENABLEREG2 (0x91400394)
#define CH4_INTSIGNAL_ENABLEREG1 (0x91400490)
#define CH4_INTSIGNAL_ENABLEREG2 (0x91400494)
#define DMAC_CFGREG              (0x91400010)
#define DMAC_CFGREG_EN           (0x91400014)
#define DMAC_LOWPOWER_CFGREG     (0x91400060)
#define DMAC_LOWPOWER_CFGREG1    (0x91400064)
#define CH1_SAR1                 (0x91400100)
#define CH1_SAR2                 (0x91400104)
#define CH2_SAR1                 (0x91400200)
#define CH2_SAR2                 (0x91400204)
#define CH3_SAR1                 (0x91400300)
#define CH3_SAR2                 (0x91400304)
#define CH4_SAR1                 (0x91400400)
#define CH4_SAR2                 (0x91400404)
#define CH1_DAR1                 (0x91400108)
#define CH1_DAR2                 (0x9140010C)
#define CH2_DAR1                 (0x91400208)
#define CH2_DAR2                 (0x9140020C)
#define CH3_DAR1                 (0x91400308)
#define CH3_DAR2                 (0x9140030C)
#define CH4_DAR1                 (0x91400408)
#define CH4_DAR2                 (0x9140040C)
#define CH1_BLOCK_TS1            (0x91400110)
#define CH1_BLOCK_TS2            (0x91400114)
#define CH2_BLOCK_TS1            (0x91400210)
#define CH2_BLOCK_TS2            (0x91400214)
#define CH3_BLOCK_TS1            (0x91400310)
#define CH3_BLOCK_TS2            (0x91400314)
#define CH4_BLOCK_TS1            (0x91400410)
#define CH4_BLOCK_TS2            (0x91400414)
#define CH1_CTL1                 (0x91400118)
#define CH1_CTL2                 (0x9140011C)
#define CH2_CTL1                 (0x91400218)
#define CH2_CTL2                 (0x9140021C)
#define CH3_CTL1                 (0x91400318)
#define CH3_CTL2                 (0x9140031C)
#define CH4_CTL1                 (0x91400418)
#define CH4_CTL2                 (0x9140041C)
#define CH1_CFG1                 (0x91400120)
#define CH1_CFG2                 (0x91400124)
#define CH2_CFG1                 (0x91400220)
#define CH2_CFG2                 (0x91400224)
#define CH3_CFG1                 (0x91400320)
#define CH3_CFG2                 (0x91400324)
#define CH4_CFG1                 (0x91400420)
#define CH4_CFG2                 (0x91400424)

/* QSPI MMIC */
#define IMR (0x8800002C)
//#define CTRLR0          (0x88000000)
#define MWCR            (0x8800000C)
#define BAUDR           (0x88000014)
#define TXFTLR          (0x88000018)
#define RXFTLR          (0x8800001C)
#define AXIAWLEN        (0x88000050)
#define AXIARLEN        (0x88000054)
#define RX_SAMPLE_DELAY (0x880000F0)
//#define SPI_CTRLR0      (0x880000F4)
#define SPI_CTRLR1 (0x88000118)

/* Timers */
#define TIMER1CONTROLREG (0x91923008)
#define TIMER2CONTROLREG (0x9192301C)
#define TIMER3CONTROLREG (0x91923030)

/* WDTS */
#define WDT_CR   (0x9192C000)
#define WDT_TORR (0x9192C004)

/*AUX ACC */
#define AUX_ACC_MISC_CTRL0 (0x84402050)
#define AUX_ACC_ECC_CTRL0  (0x84402178)
#define AUX_ACC_ECC_CTRL1  (0x8440217C)
#define AUX_ACC_ECC_CTRL2  (0x84402180)
#define AUX_ACC_RAM_CTRL0  (0x84402190)
#define IRQ_ERR_ENA_CTRL0  (0x84402194)
#define IRQ_INFO_ENA_CTRL0 (0x8440219C)

/* CRG */
#define CLK_TOP_CTRL  (0x89002000)
#define BOR_0P8_TRIM  (0x8900201C)
#define BOR_1P8_TRIM  (0x89002020)
#define RESET_LOCKOUT (0x89002034)

/* GPADC */
#define ADC_CTRL    (0x88001000)
#define GEN_CONFIG  (0x88001008)
#define OFFSET_CTRL (0x88001004)
#define CH0_CONFIG1 (0x88001014)
#define CH0_CONFIG3 (0x8800101C)
#define CH1_CONFIG1 (0x88001034)
#define CH1_CONFIG3 (0x8800103C)
#define CH2_CONFIG1 (0x88001054)
#define CH3_CONFIG1 (0x88001074)
#define CH4_CONFIG1 (0x88001094)
#define CH5_CONFIG1 (0x880010B4)
#define CH6_CONFIG1 (0x880010D4)
#define CH7_CONFIG1 (0x880010F4)
#define CH8_CONFIG1 (0x88001114)
#define CH9_CONFIG1 (0x88001134)
#define CH2_CONFIG3 (0x8800105C)
#define CH3_CONFIG3 (0x8800107C)
#define CH4_CONFIG3 (0x8800109C)
#define CH5_CONFIG3 (0x880010BC)
#define CH6_CONFIG3 (0x880010DC)
#define CH7_CONFIG3 (0x880010FC)
#define CH8_CONFIG3 (0x8800111C)
#define CH9_CONFIG3 (0x8800113C)

/* IO CTRL */
#define GPIO_00 (0x89001000)
#define GPIO_01 (0x89001004)
#define GPIO_02 (0x89001008)
#define GPIO_03 (0x8900100C)
#define GPIO_04 (0x89001010)
#define GPIO_05 (0x89001014)
#define GPIO_06 (0x89001018)
#define GPIO_07 (0x8900101C)
#define GPIO_08 (0x89001020)
#define GPIO_09 (0x89001024)
#define GPIO_10 (0x89001028)
#define GPIO_11 (0x8900102C)
#define GPIO_12 (0x89001030)
#define GPIO_13 (0x89001034)
// #define GPIO_14        (0x89001038)
// #define GPIO_15        (0x8900103C)
#define GPIO_16        (0x89001040)
#define GPIO_17        (0x89001044)
#define GPIO_18        (0x89001048)
#define GPIO_19        (0x8900104C)
#define GPIO_20        (0x89001050)
#define GPIO_21        (0x89001054)
#define FLASH_QSPI_D0  (0x890010A8)
#define FLASH_QSPI_D1  (0x890010AC)
#define FLASH_QSPI_D2  (0x890010B0)
#define FLASH_QSPI_D3  (0x890010B4)
#define FLASH_QSPI_CLK (0x890010A0)
#define FLASH_QSPI_CSN (0x890010A4)
#define MM_QSPI_CLK    (0x890010B8)
#define MM_QSPI_CSN    (0x890010BC)
#define MM_QSPI_D0     (0x890010C0)
#define MM_QSPI_D1     (0x890010C4)
#define MM_QSPI_D2     (0x890010C8)
#define MM_QSPI_D3     (0x890010CC)
#define MM_FRAME_SOT   (0x890010D4)
#define MM_IRQ         (0x890010D8)

/* MIPI */
#define CTRL                          (0x84480000)
#define MIPI_CTRL0                    (0x84480004)
#define MIPI_CTRL1                    (0x84480008)
#define FUSA_IRQ0_EN                  (0x84480214)
#define FUSA_IRQ1_EN                  (0x84480218)
#define FUSA_IRQ2_EN                  (0x8448021C)
#define DC_ESTIMATION_CONTROL_0_CH0   (0x84480044)
#define DC_COMPENSATION_CONTROL_0_CH0 (0x8448004C)

/* PWM */
#define PWM0_CSR            (0x91936000)
#define PWM0_SLOPE_STEP     (0x91936004)
#define PWM0_DITHER_CTRL    (0x91936008)
#define PWM0_NOMINAL_PERIOD (0x9193600C)
#define PWM0_MIN_PERIOD     (0x91936010)
#define PWM0_MAX_PERIOD     (0x91936014)

/* PWM */
#define PWM1_CSR            (0x91938000)
#define PWM1_SLOPE_STEP     (0x91938004)
#define PWM1_DITHER_CTRL    (0x91938008)
#define PWM1_NOMINAL_PERIOD (0x9193800C)
#define PWM1_MIN_PERIOD     (0x91938010)
#define PWM1_MAX_PERIOD     (0x91938014)

/* PWM */
#define PWM2_CSR            (0x9193A000)
#define PWM2_SLOPE_STEP     (0x9193A004)
#define PWM2_DITHER_CTRL    (0x9193A008)
#define PWM2_NOMINAL_PERIOD (0x9193A00C)
#define PWM2_MIN_PERIOD     (0x9193A010)
#define PWM2_MAX_PERIOD     (0x9193A014)

/* PWM */
#define PWM3_CSR            (0x9193C000)
#define PWM3_SLOPE_STEP     (0x9193C004)
#define PWM3_DITHER_CTRL    (0x9193C008)
#define PWM3_NOMINAL_PERIOD (0x9193C00C)
#define PWM3_MIN_PERIOD     (0x9193C010)
#define PWM3_MAX_PERIOD     (0x9193C014)

/* RX ACC*/
#define R52_ERR_IRQ_ENA_1   (0x844C0024)
#define R52_ERR_IRQ_ENA_2   (0x844C0028)
#define R52_FUNC_IRQ_ENA    (0x844C002C)
#define COMP_PRBS_1         (0x844C003C)
#define COMP_PRBS_2         (0x844C0040)
#define DECOMP_PRBS_1       (0x844C0044)
#define DECOMP_PRBS_2       (0x844C0048)
#define MON_TIMER_IN_CTRL   (0x844C006C)
#define MON_TIMER_PROC_CTRL (0x844C0074)
#define MON_TIMER_OUT_CTRL  (0x844C007C)
#define IDMA_TRIGGER_ENA    (0x844C0090)

/* SYS_Ctrl */
#define LBIST_MEM_MISC_CTRL0 (0x8900005C)
#define LBIST_MEM_MISC_CTRL1 (0x89000060)
#define PVT0_CTRL0           (0x890000B0)
#define PVT0_CTRL1           (0x890000B4)
#define PVT0_CTRL2           (0x890000B8)
#define PVT0_CTRL3           (0x890000BC)
#define PVT0_CTRL4           (0x890000C0)
#define PVT1_CTRL0           (0x890000E4)
#define PVT1_CTRL1           (0x890000E8)
#define PVT1_CTRL2           (0x890000EC)
#define PVT1_CTRL3           (0x890000F0)
#define PVT1_CTRL4           (0x890000F4)
#define PVT0_TO_CTRL0        (0x890000C4)
#define PVT1_TO_CTRL0        (0x890000F8)
#define PVT0_BYP_CTRL        (0x890000CC)
#define PVT0_IRQ_CTRL        (0x890000DC)
#define PVT1_IRQ_CTRL        (0x89000110)
#define MMINTF_SIG_CTRL      (0x89000118)
#define PMIC_FAULTB_CTRL     (0x890001E4)
#define MISC_CTRL            (0x890001F0)
#define SERDES_MISC_CTRL     (0x890001F4)

/* Artie Ctrl */
#define CAN0_CTRL            (0x89003000)
#define ETHER_CTRL           (0x89003008)
#define SP_MAIN_CFG          (0x8900300C)
#define SP0_CFG0             (0x89003010)
#define DCLS_CTRL            (0x89003018)
#define OTP_CTRL0            (0x8900301C)
#define OTP_CTRL1            (0x89003020)
#define OTP_CTRL2            (0x89003024)
#define OTP_CTRL3            (0x89003028)
#define OTP_CTRL4            (0x8900302C)
#define OTP_CTRL5            (0x89003030)
#define OTP_CTRL6            (0x89003034)
#define OTP_CTRL7            (0x89003038)
#define OTP_CTRL8            (0x8900303C)
#define OTP_CTRL9            (0x89003040)
#define OTP_CTRL10           (0x89003044)
#define OTP_CTRL11           (0x89003048)
#define OTP_CTRL12           (0x8900304C)
#define OTP_CTRL13           (0x89003050)
#define OTP_CTRL14           (0x89003054)
#define OTP_CTRL15           (0x89003058)
#define OTP_CTRL16           (0x8900305C)
#define OTP_CTRL17           (0x89003060)
#define OTP_TM_CTRL          (0x89003068)
#define CLKGEN_CTRL0         (0x8900306C)
#define CLKGEN_CTRL1         (0x89003070)
#define MEM_CTRL             (0x89003074)
#define MEM_INIT_CTRL        (0x89003078)
#define WDT_TOP_CTRL         (0x8900307C)
#define TIMERS_TOP_CTRL      (0x89003080)
#define HSM_SRAM_CTRL        (0x89003084)
#define HSM_MISC_CTRL        (0x89003088)
#define SPI_RXD_CTRL         (0x8900308C)
#define PWM_TOP_CTRL0        (0x89003090)
#define PWM_TOP_CTRL1        (0x89003094)
#define SERDES_IRQ_ENA       (0x890030A0)
#define TRNG_CHAR_CTRL       (0x890030B0)
#define TRNG_VAL_CTRL        (0x890030B8)
#define SEC_CNT_CTRL         (0x890030C8)
#define AMEM_IRQ_ENA         (0x890030D4)
#define ETHERNET_MCGR_CTRL   (0x890030EC)
#define NOC_MISC_CTRL        (0x890030F0)
#define R52_CEE_LIM_CTRL1    (0x89003104)
#define R52_CEE_LIM_CTRL2    (0x89003108)
#define R52_CEE_LIM_CTRL3    (0x8900310C)
#define R52_CEE_SNAP_CTRL    (0x89003110)
#define R52_CEE_IRQ_ENA_CTRL (0x89003124)
#define MCE_LIM_CTRL0        (0x89003134)
#define MCE_SNAP_CTRL        (0x89003138)
#define MCE_IRQ_ENA_CTRL     (0x89003140)

/* FCRU */
#define FCRU_CTRL_00 (0x89004050)
#define FCRU_CTRL_01 (0x89004054)
#define FCRU_CTRL_02 (0x89004058)
#define FCRU_CTRL_03 (0x8900405C)
#define FCRU_CTRL_08 (0x89004070)
#define FCRU_CTRL_09 (0x89004074)
#define FCRU_CTRL_10 (0x89004078)

/* SYS_mem */
#define PORT0_MISC_CTRL0 (0x84400000)
#define PORT1_MISC_CTRL0 (0x844000F4)
#define PORT0_ECC_CTRL0  (0x84400004)
#define PORT1_ECC_CTRL0  (0x844000F8)
#define PORT0_MODE_CTRL0 (0x84400008)
#define PORT1_MODE_CTRL0 (0x844000FC)
#define PORT0_TRNP_CTRL0 (0x8440000C)
#define PORT1_TRNP_CTRL0 (0x84400100)
#define IRQ_ENA_CTRL0    (0x844001E8)
#define PORT0_RAM_CTRL0  (0x84400030)
#define PORT1_RAM_CTRL0  (0x84400124)
/*Define Static register addresses -  End*/
/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
void Static_Register_Safety_Check(void);
#endif /*STATIC_REGISTER_SAFETY_H */
