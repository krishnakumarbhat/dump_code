/*===========================================================================*\
 * FILE: mcal_init.c
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
 *   This file contains functions to initialize the MCAL (Microcontroller Abstraction Layer) modules.
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
/*===========================================================================*\
 * Other Header Files
\*===========================================================================*/
#include "mcal_init.h"
#include "Can.h"
#include "Driver_Gpio.h"
#include "Driver_Port.h"
#include "Eth.h"
#include "Eth_Mac_Utils.h"
#include "Eth_PBcfg.h"
#include "PHY_User_Cbk.h"
#include "Port.h"
#include "Port_PBcfg.h"
#include "Wdg_182_iND13400.h"
#include "Wdg_182_iND13400_PBcfg.h"
#include "artie_sfrs.h"
#include "chandra_r52_irq.h"
#include "chandra_sfrs_base.h"
#include "crg_sfrs.h"
#include "dbgm_ctrl_sfrs.h"
#include "dd_cmu.h"
#include "dd_gpt.h"
#include "dd_mipi.h"
#include "dd_mmic.h"
#include "gpio_sfrs.h"
#include "ioctrl_sfrs.h"
#include "serdes_sfrs.h"
#include "smc_cal.h"
#include "sysctrl_sfrs.h"
/*===========================================================================*\
 * Local Preprocessor #define Constants
\*===========================================================================*/
#define CRG       ((volatile CRG_SFRS_t *)CRG_base)
#define SERDES    ((volatile SERDES_SFRS_t *)SERDES_base)
#define SYSCTRL   ((volatile SYSCTRL_SFRS_t *)SYSCTRL_base)
#define IOCTRL    ((volatile IOCTRL_SFRS_t *)IOCTRL_base)
#define GPIO      ((volatile GPIO_SFRS_t *)GPIO_base)
#define DBGM_CTRL ((volatile DBGM_CTRL_SFRS_t *)DBGM_CTRL_base)
#define ARTIE     ((volatile ARTIE_SFRS_t *const)ARTIE_base)
void CAN_Trcv_Init(void);
void disable_ethernet_clocks(void);
/*===========================================================================*\
 * Local Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Local Type Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Local Object Definitions
\*===========================================================================*/
#define MCAL_INIT_TIME_MEASURE_ENABLE (0U)
#define ETH_LANEA_POWERDOWN_VALUE     ((uint32)(0x000017D8))
#ifdef UART_MODULE_ENABLE
extern ARM_DRIVER_PORT Driver_Port0;
static ARM_DRIVER_PORT *Port = &Driver_Port0;
#endif
/*===========================================================================*\
* External Object Declarations
\*===========================================================================*/

/*===========================================================================*\
* Local Function Prototypes
\*===========================================================================*/
#ifndef DEVELOPMENT_ONLY
static void disable_serdes_portb(void);
#endif
#ifdef DEVELOPMENT_ONLY
static void deassert_serdes(void);
/* SRDR PORTB used for AURORA Tracing only */
static void program_txPLL(void);
static void init_serdes(void);
static void configure_serdes_for_trace(void);
#endif
/*===========================================================================*\
* Exported Function Prototypes
\*===========================================================================*/
/*===========================================================================*\
 * Local Inline Function Definitions and Function-Like Macros
\*===========================================================================*/

/*===========================================================================*\
 * Function Definitions
\*===========================================================================*/
/*****************************************************************************
 *. Name: disable_serdes_portb
 *.    Disable SERDES PORTB used for AURORA clock interface clk_srds_tx1 clk_hsst
 *.    This to disable SRDES_TX_P and SRDES_TX_N connected to J0901-17 and 19
 *.    This to disable debug/instrumentation clocks that can create noise for EMC
 *. Parameters:void
 *.
 *. Return Value: None.
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
#ifndef DEVELOPMENT_ONLY
static void disable_serdes_portb(void)
{
   /* SRDES PortB is used for AURORA Debug interface and disbaling it for EMC */
   CRG->CLK_TOP_CTRL.f.CTL_CG_HSST_CKEN = 0x0;
   /* Powerdown LANE B transmitter */
   SERDES->LANEB_POWERDOWN_0.f.TXPDB = 0x1;
}
#endif
void CAN_Trcv_Init(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK CAN_Trcv_Init>                          DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK CAN_Trcv_Init>                          DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   SYSCTRL->DEBUG_CODE        = 0x1DACCE55;
   IOCTRL->GPIO_20.f.FUNC_SEL = 0x1;
   IOCTRL->GPIO_20.f.IE       = 0x0;
   IOCTRL->GPIO_20.f.DS       = 0x0;
   IOCTRL->GPIO_20.f.ST       = 0u;
   IOCTRL->GPIO_20.f.PE       = 0u;
   IOCTRL->GPIO_20.f.PS       = 1u;
   IOCTRL->TEST_BUS_00 |= (1U << 20U); /* As per HSI this has to be Pull high : Make it high to initiate comm */

} /* End of CAN_Trcv_Init */

#ifdef DEVELOPMENT_ONLY
static void deassert_serdes(void)
{
   /* Powerdown LANE B transmitter */
   SERDES->LANEB_POWERDOWN_0.f.TXPDB = 0x0;
   /* Deasserting reset on Transmitter lanes */
   SERDES->TXPLL_CONTROL_0.f.TXPLL_CLKRESETEN = 0x0;
   SERDES->TXPLL_CONTROL_0.f.TXPLL_CLKRESET   = 0x0;
   /* Not using FIFO path hence keeping it off */
   SERDES->LANEB_DATAPATH_0.f.TXFIFO_RESETB = 0x1;
}

static void program_txPLL(void)
{
   /* Programming PLL to generate 2.5Ghz VCO signal tone */
   SERDES->TXPLL_DIVIDER1_0.f.TXPLL_AUXDIV    = 0x011;
   SERDES->TXPLL_DIVIDER1_0.f.TXPLL_DSMPD     = 0x0;
   SERDES->TXPLL_DIVIDER1_0.f.TXPLL_FBDIV     = 0x03E;
   SERDES->TXPLL_DIVIDER1_0.f.TXPLL_FBDIV_SEL = 0x0;

   SERDES->TXPLL_DIVIDER2_0.f.TXPLL_FRAC   = 0x800000;
   SERDES->TXPLL_DIVIDER2_0.f.TXPLL_REFDIV = 0x01;
   /* Enabling PLL */
   SERDES->TXPLL_CONTROL_0.f.TXPLL_AUXDIVPD = 0x0;
   SERDES->TXPLL_CONTROL_0.f.TXPLL_PD       = 0x0;

   /* Whether to enable outputting VCO freq of 2.5Ghz */
   SERDES->TXPLL_CONTROL_0.f.TXPLL_FOUTVCO_EN = 0x1;
   while (!SERDES->TXPLL_STATUS_0.f.TXPLL_LOCK)
      ;
}

static void init_serdes(void)
{
   SERDES->LANEB_DATAPATH_0.f.SERMODEB        = 0x1;
   SERDES->LANEB_DATAPATH_0.f.TX_DATA_SELECTB = 0x0;
   SERDES->LANEB_DATAPATH_0.f.TXFIFO_ENABLEB  = 0x0;
   SERDES->LANEB_DATAPATH_0.f.TXDATA_FLIPENDB = 0x1;
   SERDES->LANEB_DRIVER1_0.f.TXDRVB           = 0x7;
   SERDES->LANEB_DRIVER2_0                    = 0x00FFFFFF;
   SERDES->LANEB_DATAPATH_0.f.TXPOSTDIVB      = 0x0;
   SERDES->LANEB_DATAPATH_0.f.TXPOSTDIVENB    = 0x1;
}

static void configure_serdes_for_trace(void)
{
   program_txPLL();
   init_serdes();
   deassert_serdes();
}
static void z_trace_config(void)
{
   configure_serdes_for_trace();
   DBGM_CTRL->AURORA_CTRL1.f.TX_ALIGNED       = 1;
   DBGM_CTRL->AURORA_CTRL1.f.TX_VERIFY        = 1;
   DBGM_CTRL->AURORA_CTRL0.f.STATIC_CC_PERIOD = 0xFFFF;
}
#endif

/*****************************************************************************
 *. Name: mcal_init
 *.    Intializes all the MCAL modules and
 *.
 *. Parameters:void
 *.
 *. Return Value: None.
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
volatile NXP_RTL_PHY_MODEL_T lMcal_Init_Phy_Model;
__attribute__((optnone)) void MCAL_Init(void)
{
   // while (!go)
   //  {
   // } /* enable this while loop when you want to debug in Trace*/

#if MCAL_INIT_TIME_MEASURE_ENABLE
   IOCTRL->GPIO_11.f.FUNC_SEL = 0x0; /* DIO Mode */
   IOCTRL->GPIO_11.f.IE       = 1;   /* Output so IE buffer not needed */
   IOCTRL->GPIO_11.f.DS       = 0;
   IOCTRL->GPIO_11.f.ST       = 0;
   IOCTRL->GPIO_11.f.PE       = 0;
   IOCTRL->GPIO_11.f.PS       = 0;
   GPIO->GPIO_SWPORTB_DDR.f.GPIO_SWPORTB_DDR |= 0x08; /* As Output */
   GPIO->GPIO_SWPORTB_DR.f.GPIO_SWPORTB_DR |= 0x08u;
#endif
   /* To initialize the clock and distribute the pll */
   Mcu_Init(&Mcu_Config);

   while (MCU_PLL_LOCKED != (Mcu_PllStatusType)Mcu_GetPllStatus())
      ;
   Mcu_InitClock(0);
   Mcu_DistributePllClock();

#ifndef DEVELOPMENT_ONLY
   /* Disable SERDES PORTB used for AURORA clock interface */
   disable_serdes_portb();
#endif
   /*Port Pin Initialization*/
   Port_Init(&Port_Config[0]);
/*Enable UART configuration*/
#ifdef UART_MODULE_ENABLE
   Port->SetMode(ARM_PORT_A1A4, ARM_PIN_MODE_UART, (ARM_PORT_CFG_OUTPUT | ARM_PORT_CFG_READEN));
#endif
   /*GPT and driver Initialization*/
   Init_GPT_Wrapper();

   /* ADC and driver Initialization*/
   Adc_Init(&Adc_Config);
   Init_ADC_Channels();
   IoHwAb_Adc_Main_5ms();

   Read_Board_Revision();
   Check_RDI_Log_Connection();
   CAN_Trcv_Init();

   Spi_Init(&Spi_Config);
   Fls_Init(&Fls_Config);

   /* ToDo: DMA initialization is currently commented out as it is impacting FCRU channel 55 - Artie NOC.
   Till the configuration is fixed, DMA initialization remains disabled. */
   /*Dma_Initialization*/
   Dma_Init(&Dma_Config);
#if DEVELOPMENT_ONLY
   /* PS_CLK_4MHz / PWM_1 and HSD_EN / PWM_0 are not needed in Gen8 */
   /* PS_CLK_4MHz is not needed in as PMIC creates its own clock    */
   /* HSD_EN is not used for this application */
   /*Pwm Initialization*/
   // Pwm_Init(&Pwm_Config);
#endif
   /*I2c Initialization*/
   I2c_Init(&I2c_Config);

   /*Uart Initialization*/
   Uart_Init(&Uart_Config);

   /****************Eth Bring UP****************************/
   // Configure IOCTRL for MDIO and MDC
   IOCTRL->GPIO_24.f.FUNC_SEL = 0x1; // ETH_MDIO
   IOCTRL->GPIO_24.f.DS       = 0xF;
   IOCTRL->GPIO_25.f.FUNC_SEL = 0x1; // ETH_MDC
   IOCTRL->GPIO_25.f.DS       = 0xF;

   // Configure IOCTRL for RESETB on PHY
   if (Get_Board_Revision() >= BOARD_REV_A2P0)
   {
      // Configure IOCTRL for RESETB on PHY
      IOCTRL->GPIO_14.f.FUNC_SEL = 0x0; /* DIO Mode */
      IOCTRL->GPIO_14.f.IE       = 0x0; /* Output so IE buffer not needed */
      IOCTRL->GPIO_14.f.DS       = 0xF;
      IOCTRL->GPIO_14.f.ST       = 1u;
      IOCTRL->GPIO_14.f.PE       = 1u;
      IOCTRL->GPIO_14.f.PS       = 1u;
      GPIO->GPIO_SWPORTB_DR.f.GPIO_SWPORTB_DR |= 0x40;   /* Write High to C0 */
      GPIO->GPIO_SWPORTB_DDR.f.GPIO_SWPORTB_DDR |= 0x40; /* As Output */
   }
   else if (BOARD_REV_A0 == Get_Board_Revision())
   {
      // Configure IOCTRL for RESETB on PHY
      IOCTRL->GPIO_14.f.FUNC_SEL = 0x4; /* TEST_BUS Mode */
      IOCTRL->GPIO_14.f.IE       = 0x0; /* Output so IE buffer not needed */
      IOCTRL->GPIO_14.f.DS       = 0xF;
      IOCTRL->GPIO_14.f.ST       = 1u;
      IOCTRL->GPIO_14.f.PE       = 1u;
      IOCTRL->GPIO_14.f.PS       = 1u;
      GPIO->GPIO_SWPORTB_DR.f.GPIO_SWPORTB_DR |= 0x40;   /* Write High to C0 */
      GPIO->GPIO_SWPORTB_DDR.f.GPIO_SWPORTB_DDR |= 0x40; /* As Output */
   }

   GPIO->GPIO_SWPORTC_DR.f.GPIO_SWPORTC_DR |= 0x01;   /* Write High to C0 */
   GPIO->GPIO_SWPORTC_DDR.f.GPIO_SWPORTC_DDR |= 0x01; /* As Output */

   /*For AL non instrumental board updated all the below Eth Pin as input DIO/Test Mux Pin with No pull*/
   if (Get_Board_Revision() == BOARD_REV_B0CVAL)
   {
      IOCTRL->GPIO_02.f.FUNC_SEL = 0x0; /* DIO */
      IOCTRL->GPIO_02.f.IE       = 0x1; /* Input */
      IOCTRL->GPIO_02.f.PE       = 0u;  /*No Pull*/

      IOCTRL->GPIO_24.f.FUNC_SEL = 0x4; /* TEST_BUS */
      IOCTRL->GPIO_24.f.IE       = 0x1; /* Input */
      IOCTRL->GPIO_24.f.PE       = 0u;  /*No Pull*/

      IOCTRL->GPIO_25.f.FUNC_SEL = 0x4; /* TEST_BUS */
      IOCTRL->GPIO_25.f.IE       = 0x1; /* Input */
      IOCTRL->GPIO_25.f.PE       = 0u;  /*No Pull*/

      IOCTRL->GPIO_14.f.FUNC_SEL = 0x0; /* DIO */
      IOCTRL->GPIO_14.f.IE       = 0x1; /* Input */
      IOCTRL->GPIO_14.f.PE       = 0u;  /*No Pull*/
   }

   // CAN0: STDBy pin

   // CAN1: STDBy pin
#ifdef DEVELOPMENT_ONLY
   /* SRDR PORTB used for AURORA Tracing only */
   z_trace_config();
#endif

   /********************************************************/
   MIPI_Enable();
   Calib_Init_Function();
   (void)RFE_Initialization();
   /* Initialize Wdg */
   Wdg_182_iND13400_Init(&Wdg_182_iND13400_Config);
   if (1 == k_internal_wdg_disable_smc)
   {
      Wdg_182_iND13400_SetMode(WDGIF_OFF_MODE);
   }
#if (TRUE == DISABLE_INT_WDG)
   Wdg_182_iND13400_SetMode(WDGIF_OFF_MODE);
#endif

#ifdef DEVELOPMENT_ONLY
   #if (PS_2MHZ_CLK_DITHER_ENABLE == CLOCK_ENABLED)
   PS_Clock_Init(); /*call 2mhz and 8Mh dithering during initialization*/
   #endif           /*end of PS_2MHZ_CLK_DITHER_ENABLE*/
#endif              /*end of DEVELOPMENT_ONLY*/
   /* Initialize CMU */
   CMU_Init();

   lMcal_Init_Phy_Model = Detect_PHY_Model();
}

static DMA_strChannelStatusInfo channelState;
static volatile uint32 DataTransferCount = 0;
/**
 * @fn            Channel1_EndNotification
 * @ID            NA
 * @requirements
 * @design
 * @brief         Notification for the completion of Channel 1 transfer.
 * @param [in]    None
 * @param [in]    None
 * @param [out]   None
 * @return        None
 */
void Channel1_EndNotification(void)
{
   DataTransferCount = Dma_ChannelGetDataCount(CHANNEL_ID_1);
   (void)DataTransferCount;

   Dma_ChannelGetStatus(CHANNEL_ID_1, &channelState);
   (void)channelState;
}

/*****************************************************************************
 *. Name: disable_ethernet_clocks
 *.    Disable Ethernet Tx and Rx clocks to reduce noise for EMC testing.
 *.    This will disable the Ethernet functionality and should only be used for EMC/EMI testing or Non-Ethernet variants.
 *. Parameters:void
 *.
 *. Return Value: None.
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
void disable_ethernet_clocks(void)
{
   ARTIE->CLKGEN_CTRL0.f.CTL_CG_SRDS_RX0_ENA_CK = 0;
   ARTIE->CLKGEN_CTRL0.f.CTL_CG_SRDS_TX0_ENA_CK = 0;
   /* IR-1863 Based on Indie feedback SERDES_LANEA Power down to */

   SERDES->LANEA_POWERDOWN_0.r = ETH_LANEA_POWERDOWN_VALUE;

#if 0 /* This is for information on the translation of the assigned value 0x000017D8 */
   /* TX pad / serializer off (active-high powerdown) */
   SERDES->LANEA_POWERDOWN_0.f.TXPDA      = 1;
   /* RX front-end / CDR channel off */
   SERDES->LANEA_POWERDOWN_0.f.RCVENA     = 0;
   SERDES->LANEA_POWERDOWN_0.f.RXBIAS_PDA = 1;
   SERDES->LANEA_POWERDOWN_0.f.RXCH_PDA   = 1;
   SERDES->LANEA_POWERDOWN_0.f.RXPKDETENA = 0;
   /* Keep DFE / eye-monitor powered down */
   SERDES->LANEA_POWERDOWN_0.f.PDDFEA     = 1;
   SERDES->LANEA_POWERDOWN_0.f.PDEMA      = 1;
   SERDES->LANEA_POWERDOWN_0.f.CTLEEN_DFEA = 0;
   SERDES->LANEA_POWERDOWN_0.f.CTLEEN_EMA  = 0;
   SERDES->LANEA_POWERDOWN_0.f.DISABLE_CDRGATEA = 0;
   /* Hold RX datapath in reset */
   SERDES->LANEA_POWERDOWN_0.f.RESETDESA  = 1;
#endif
}
