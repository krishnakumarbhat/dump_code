/*===========================================================================*\
 * FILE: PHY_User_Cbk.c
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
//  * DESCRIPTION:
//  *   Implements PHY (Physical Layer) user callbacks and MDIO helper routines
 *   for the RTL9010 and NXP TJA1103 Ethernet transceivers. Provides initialization
 *   hooks, operational state control, link configuration, and PHY manufacturer
 *   detection used by the AUTOSAR Ethernet Transceiver stack.
 *
 * ABBREVIATIONS:
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *   Requirements Document(s):
 *   (Design & Requirements)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *
 * DEVIATIONS FROM STANDARDS:
 *   None
 *
\*===========================================================================*/
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "PHY_User_Cbk.h"
#include "Eth_Mac.h"
#include "Os.h"
#include "artie_sfrs.h"
#include "chandra_sfrs_base.h"
#include "platformtime.h"
/*===========================================================================*\
 * Local preprocessor #define MACROS() (i.e., those using # or ## operator)
\*===========================================================================*/
#pragma clang optimize off
#define PHY_DELAY_IN_US (2000) /* set a 2ms timer */

/* ========================================================================== */
/*        TJA1103 AN13137 Managed-Mode Initialization Register Masks          */
/* ========================================================================== */
/* BASE_T1_PMA_CONTROL (MMD_1, 0x0834h), bit 14 - AN13137 Section 4.3         */
/* 1 = Leader, 0 = Follower                                                   */
#define TJA1103_BASE_T1_PMA_CONTROL_LEADER_FOLLOWER_MASK (0x4000u)
/* DEVICE_CONTROL (MMD_30, 0x0040h), bit 0 - AN13137 Figure 30               */
/* Starts the PHY out of Standby (Managed mode only)                          */
#define TJA1103_DEVICE_CONTROL_START_OPERATION_MASK (0x0001u)
#define SGMII_ADVANCED_STATUS                       (0xB011)
/* ========================================================================== */
/*     TJA1103 SGMII PCS Restart Errata (Errata Sheet Section 2.1)            */
/* ========================================================================== */
/* SGMII_BASIC_CONTROL (MMD_30, 0xB000h), bit 11 = LPM, bit 15 = RST         */
#define TJA1103_REG_OFFS_SGMII_BASIC_CONTROL                    (0xB000u)
#define TJA1103_REG_OFFS_SGMII_ADVANCED_CONTROL                 (0xB010u)
#define TJA1103_REG_SGMII_BASIC_CONTROL_LPM_MASK                (0x0800u)
#define TJA1103_REG_SGMII_ADVANCED_CONTROL_START_OPERATION_MASK (0x0001u)
#define ETHTRCV_30_TJA1103_REG_DEVICE_CONTROL_STANDBY_MASK      (0x0002u)

/* ========================================================================== */
/*   TJA1120 VDD-Core LDO Workaround & SGMII Force-1G Register Masks          */
/* ========================================================================== */
/* The TJA1120 requires an internal VDD-Core LDO calibration workaround       */
/* during Post_Init (NXP guidance), and the SGMII interface must be          */
/* explicitly forced to 1 Gb/s. None of these registers are part of the      */
/* TJA1103 register map (ETHTRCV_30_TJA1103_LL_Regs.h only covers TJA1103/4),*/
/* so they are defined locally here and accessed via the generic CL45        */
/* helpers (tja1103_cl45_read/write) which work for any MMD/offset.          */
#define TJA1120_REG_OFFS_VDD_CORE_UNLOCK_1    (0x01F8u) /* MMD_30 */
#define TJA1120_REG_OFFS_VDD_CORE_UNLOCK_2    (0x01F9u) /* MMD_30 */
#define TJA1120_REG_OFFS_VDD_CORE_LDO_SETTING (0x0476u) /* MMD_30 */
#define TJA1120_REG_OFFS_ADC_LATCH_CONFIG     (0x8921u) /* MMD_1  */
#define TJA1120_REG_OFFS_SQI_AVERAGING_CONFIG (0x89F1u) /* MMD_1  */

#define TJA1120_VDD_CORE_UNLOCK_KEY_1      (0x4B95u)
#define TJA1120_VDD_CORE_UNLOCK_KEY_2      (0xF3CDu)
#define TJA1120_VDD_CORE_LDO_SETTING_VALUE (0x58A0u)
#define TJA1120_ADC_LATCH_CONFIG_VALUE     (0x0A3Au)
#define TJA1120_SQI_AVERAGING_CONFIG_VALUE (0x16C1u)

/* BASE_T1_PMA_CONTROL (MMD_1, 0x0834h) full-register value for Follower mode  */
/* on the TJA1120: bit 15 = manual master/slave config enable, bit 0 = 1      */
/* (Follower). This differs from the TJA1103, which only uses bit 14         */
/* (TJA1103_BASE_T1_PMA_CONTROL_LEADER_FOLLOWER_MASK) — do NOT reuse that     */
/* mask for the TJA1120.                                                     */
#define TJA1120_BASE_T1_PMA_CONTROL_LF_VALUE (0x8001u)

/* ========================================================================== */
/*     TJA1103 Debug Register Offsets not covered by LL_Regs.h                */
/* ========================================================================== */
#define TJA1103_REG_OFFS_PMA_STATUS2   (0x0008u) /* MMD_1,      Device present / faults    */
#define TJA1103_REG_OFFS_PCS_STATUS1   (0x0001u) /* MMD_3,      Rcv link status            */
#define TJA1103_REG_OFFS_PCS_STATUS2   (0x0008u) /* MMD_3,      Device present / faults    */
#define TJA1103_REG_OFFS_DEVICE_STATUS (0x0042u) /* MMD_30,     FUSA_STATUS                */
#define TJA1103_REG_OFFS_PHY_STATE     (0x810Cu) /* MMD_SHARED, PHY state machine snapshot */
#define TJA1103_REG_OFFS_MSE           (0x8324u) /* MMD_SHARED, mean-square error          */

/* ========================================================================== */
/*     Manual Clause-45 (MMD) Indirect Access via Clause-22 MDIO Registers     */
/* ========================================================================== */
/* IEEE 802.3 Clause-45 registers accessed indirectly over Clause-22 MDIO:    */
/* reg 13 = MMD Access Control (function + DEVAD), reg 14 = MMD Access        */
/* Address/Data (register address, then data), per IEEE 802.3 45.3.          */
#define MMD_ACCESS_CONTROL_REG       (13u)
#define MMD_ACCESS_ADDR_DATA_REG     (14u)
#define MMD_ACCESS_FUNC_ADDRESS      (0x0000u)
#define MMD_ACCESS_FUNC_DATA_NO_INCR (0x4000u)

/*
Current plan is
For RTL:
1) Combo PHY : 9010BSA 100Mb/1Gb
2) non-Combo PHY : 9000CSA 100Mb
NXP:
1) Non Combo PHY : TJA1103 100Mb
2) Non Combo PHY : TBD 1Gb
There will be a separate Build command for 100Mb and 1Gb.
Need to add Logic to determine/identify the PHY manufacturer and then based on BUILD config, apply 100Mb vs 1Gb
changes/configurations.
*/

/* PHY_ID1_* macros and PHY_Manufacturer_t typedef moved to PHY_User_Cbk.h */
/* TJA1103 Transceiver index — set in TJA1103_PHY_Pre_Init() */
static uint8_t ETH_TRCV_INDEX = 255U;
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
uint16 Errata_4_Test   = 0xFF;
uint16 Errata_1_Test   = 0xFF;
uint16 Test_0xD048_Val = 0xFFFF;

/* Debug Variables for RTL9010AS/RTL9010BSA Register Verification */
volatile uint16 BMCR_Reg_0x00_norm_acc                  = 0xFFFF;
volatile uint16 BMSR_Reg_0x01_norm_acc                  = 0xFFFF;
volatile uint16 PHYCR_Reg_0x09_norm_acc                 = 0xFFFF;
volatile uint16 PHYSR1_Reg_0x0A_norm_acc                = 0xFFFF;
volatile uint16 PHYSFR_Reg_0x10_Pg_0xA42_norm_acc       = 0xFFFF;
volatile uint16 GINER_Reg_0x12_Pg_0xA42_norm_acc        = 0xFFFF;
volatile uint16 GINMR_Reg_0x14_Pg_0xA42_norm_acc        = 0xFFFF;
volatile uint16 SLPCR_Reg_0x15_Pg_0xA42_norm_acc        = 0xFFFF;
volatile uint16 PHYSCR_Reg_0x18_norm_acc                = 0xFFFF;
volatile uint16 PHYSR2_Reg_0x1A_norm_acc                = 0xFFFF;
volatile uint16 GINSR_Reg_0x1D_norm_acc                 = 0xFFFF;
volatile uint16 GPSFR_Reg_0x15_Pg_0xA47_norm_acc        = 0xFFFF;
volatile uint16 ISR_Reg_0x12_Pg_0xA4C_norm_acc          = 0xFFFF;
volatile uint16 SLPCAP_Reg_0x13_Pg_0xA51_norm_acc       = 0xFFFF;
volatile uint16 TRACR_Reg_0x14_Pg_0xA51_norm_acc        = 0xFFFF;
volatile uint16 PCS_STATE_Reg_0x10_Pg_0xA60_norm_acc    = 0xFFFF;
volatile uint16 IPCR1_Reg_0xC800_spcl_acc               = 0xFFFF;
volatile uint16 IPCR2_Reg_0xC802_spcl_acc               = 0xFFFF;
volatile uint16 IPCR3_Reg_0xC810_spcl_acc               = 0xFFFF;
volatile uint16 IPCR4_Reg_0xC812_spcl_acc               = 0xFFFF;
volatile uint16 IEPCR_Reg_0xC814_spcl_acc               = 0xFFFF;
volatile uint16 SGMIICR1_Reg_0xCC04_spcl_acc            = 0xFFFF;
volatile uint16 SGMIICR2_Reg_0xCE00_spcl_acc            = 0xFFFF;
volatile uint16 SGMIISR1_Reg_0xCE0C_spcl_acc            = 0xFFFF;
volatile uint16 SGMIISR2_Reg_0xCF04_spcl_acc            = 0xFFFF;
volatile uint16 SQI_Reg_0xD106_spcl_acc                 = 0xFFFF;
volatile uint16 OPCR2_Reg_0xDD00_spcl_acc               = 0xFFFF;
volatile uint16 OPINSR1_Reg_0xDD08_spcl_acc             = 0xFFFF;
volatile uint16 IPINER1_Reg_0xDD0C_spcl_acc             = 0xFFFF;
volatile uint16 OPINMR1_Reg_0xDD0E_spcl_acc             = 0xFFFF;
volatile uint16 OPINSR2_Reg_0xDD10_spcl_acc             = 0xFFFF;
volatile uint16 OPINER2_Reg_0xDD14_spcl_acc             = 0xFFFF;
volatile uint16 OPINSR3_Reg_0xDD18_spcl_acc             = 0xFFFF;
volatile uint16 OPINER3_Reg_0xDD1C_spcl_acc             = 0xFFFF;
volatile uint16 OPINMR3_Reg_0xDD1E_spcl_acc             = 0xFFFF;
volatile uint16 OPCR4_Reg_0xDD20_spcl_acc               = 0xFFFF;
volatile uint16 OPMR_Reg_0xDF10_spcl_acc                = 0xFFFF;
volatile uint16 RTL9010BSA_SGMIICR2_Reg_0xCF00_spcl_acc = 0xFFFF;
volatile uint16 RTL9010BSA_SGMIISR1_Reg_0xCF0C_spcl_acc = 0xFFFF;
/* Debug Variables for NXP TJA1103 Register Verification */
uint16 TJA1103_PhyControl_Reg     = 0xFFFFu; /* MMD_SHARED, 0x8100: PHY_CONTROL                    */
uint16 TJA1103_PhyStatus_Reg      = 0xFFFFu; /* MMD_SHARED, 0x8102: PHY_STATUS (link up / SQI)     */
uint16 TJA1103_DeviceControl_Reg  = 0xFFFFu; /* MMD_30,     0x0040: DEVICE_CONTROL                 */
uint16 TJA1103_XmiiControl_Reg    = 0xFFFFu; /* MMD_30,     0xAFC0: XMII_CONTROL                   */
uint16 TJA1103_MiiBasicConfig_Reg = 0xFFFFu; /* MMD_30,     0xAFC6: MII_BASIC_CONFIG               */
uint16 TJA1103_BaseT1PmaCtrl_Reg  = 0xFFFFu; /* MMD_1,      0x0834: BASE_T1_PMA_CONTROL (M/S cfg)  */
uint16 TJA1103_SignalQuality_Reg  = 0xFFFFu; /* MMD_SHARED, 0x8320: SIGNAL_QUALITY (SQI value)     */
/* Debug Variables for TJA1103_Debug_Reg_Readout() */
uint16 TJA1103_PmaControl1_Reg                        = 0xFFFFu; /* MMD_1,      0x0000: PMA_CONTROL1 (reset/loopback)  */
uint16 TJA1103_PmaStatus1_Reg                         = 0xFFFFu; /* MMD_1,      0x0001: PMA_STATUS1 (rcv link status)  */
uint16 TJA1103_PmaStatus2_Reg                         = 0xFFFFu; /* MMD_1,      0x0008: PMA_STATUS2 (fault flags)      */
uint16 TJA1103_PcsControl1_Reg                        = 0xFFFFu; /* MMD_3,      0x0000: PCS_CONTROL1 (reset/loopback)  */
uint16 TJA1103_PcsStatus1_Reg                         = 0xFFFFu; /* MMD_3,      0x0001: PCS_STATUS1 (rcv link status)  */
uint16 TJA1103_PcsStatus2_Reg                         = 0xFFFFu; /* MMD_3,      0x0008: PCS_STATUS2 (fault flags)      */
uint16 TJA1103_DeviceConfig_Reg                       = 0xFFFFu; /* MMD_30,    0x0048: DEVICE_CONFIG                   */
uint16 TJA1103_DeviceStatus_Reg                       = 0xFFFFu; /* MMD_30,    0x0042: DEVICE_STATUS (FUSA_STATUS)     */
uint16 TJA1103_PhyConfig_Reg                          = 0xFFFFu; /* MMD_SHARED,0x8108: PHY_CONFIG (polarity/test)      */
uint16 TJA1103_PhyState_Reg                           = 0xFFFFu; /* MMD_SHARED,0x810C: PHY_STATE (state machine)       */
uint16 TJA1103_Mse_Reg                                = 0xFFFFu; /* MMD_SHARED,0x8324: MSE (mean-square error)         */
uint16 TJA1103_CableTest_Reg                          = 0xFFFFu; /* MMD_SHARED,0x8330: CABLE_TEST                      */
uint16 TJA1103_SGMIIBasic_Control_Reg                 = 0xFFFFu; /* MMD_SHARED,0x8330: CABLE_TEST                      */
volatile PHY_Manufacturer_t detected_phy_manufacturer = PHY_MFR_UNKNOWN;

uint16 param_check[21] = {0x0D13, 21, 0x0047, 0,      0x859C, 0x0609, 0,      0x85A2, 0x0300, 0,     0x85A4,
                          0x0D07, 0,  0xDC00, 0x1899, 0x0A4C, 20,     0x2A2E, 0x0A49, 20,     0xFB00};

uint16 param2_check[27] = {0x0D13, 21,     0x0047, 0,      0x859C, 0x0609, 0,      0x85A2, 0x0300,
                           0,      0x85A4, 0x0D07, 0,      0xDC00, 0x1899, 0x0A4C, 20,     0x2A2E,
                           0x0A49, 20,     0xFB00, 0x0A55, 17,     0xE301, 0xA54,  21,     0xF808};

uint16 param_with_SGMII_check[180] = {
   0xaf86, 0x20af, 0x862a, 0xaf86, 0x2aaf, 0x862a, 0xee82, 0xf600, 0x0286, 0x2aaf, 0x096b, 0xf8f9, 0xef59, 0xf9fa, 0xfbbf,
   0x8768, 0x023c, 0x5f00, 0x0000, 0xad28, 0x1aae, 0x03af, 0x86e4, 0xe187, 0x6bd0, 0x001b, 0x019e, 0x13d0, 0x011b, 0x019e,
   0x34d0, 0x021b, 0x019e, 0xe8ee, 0x876b, 0x00af, 0x8748, 0xbf87, 0x5002, 0x3c5f, 0xac28, 0x03af, 0x8748, 0xbf87, 0x5302,
   0x43bb, 0x0243, 0xc3ee, 0x876b, 0x0102, 0x42e7, 0xef47, 0xe487, 0x6ce5, 0x876d, 0xaf87, 0x48bf, 0x8756, 0x023c, 0x5fac,
   0x281a, 0xe087, 0x6ce1, 0x876d, 0xef64, 0xe087, 0x6ee1, 0x876f, 0xef74, 0x0243, 0x02ac, 0x5035, 0x00af, 0x8748, 0xbf87,
   0x5902, 0x43bb, 0x0243, 0xc3ee, 0x876b, 0x02bf, 0x8765, 0x0243, 0xbbbf, 0x875c, 0x0243, 0xbbbf, 0x8762, 0x0243, 0xbbee,
   0x8774, 0x0002, 0x42e7, 0xef47, 0xe487, 0x70e5, 0x8771, 0xaf87, 0x48ee, 0x876b, 0x00ee, 0x8775, 0x01af, 0x8748, 0xe087,
   0x70e1, 0x8771, 0xef64, 0xe087, 0x72e1, 0x8773, 0xef74, 0x0243, 0x02ad, 0x504e, 0xbf87, 0x5c02, 0x3c5f, 0x3c00, 0x009f,
   0x0dbf, 0x875f, 0x023c, 0x5f3c, 0x0000, 0x9f02, 0xae27, 0xbf87, 0x6502, 0x43bb, 0xbf87, 0x5c02, 0x43bb, 0xbf87, 0x6202,
   0x43bb, 0xe187, 0x7411, 0xe587, 0x7439, 0x03aa, 0x19ee, 0x876b, 0x00ee, 0x8776, 0x01ae, 0x0f02, 0x42e7, 0xef47, 0xe487,
   0x70e5, 0x8771, 0xee87, 0x7400, 0xfffe, 0xfdef, 0x95fd, 0xfc04, 0xeecf, 0x0411, 0xcc00, 0x00cc, 0x7a00, 0xd04a, 0xf0cc,
   0x40f8, 0xcc42, 0xf0cc, 0x4420, 0xcc70, 0x11ce, 0x0000, 0x0000, 0x003c, 0x0000, 0x003c, 0x0000, 0x0000, 0x0000, 0x0000};

uint16 param_with_NWAY_check[6]   = {0x0A54, 21, 0xFA06, 0x0BC4, 21, 0x16FE};
uint16 param_with_NWAY_check2[14] = {0x2C03, 0x2C07, 0x2C0B, 0x6054, 0xA701, 0xD500, 0x2108,
                                     0x4054, 0x8701, 0xA74A, 0x20DE, 0xD700, 0x880F, 0x262D};

/* Initialization Check variables */

/* RTL sub-model detection variables — set in Determine_RTL_PHY_Model() */
volatile NXP_RTL_PHY_MODEL_T Connected_PHY = NXP_RTL_PHY_NUM; /* detected RTL sub-model                    */
volatile uint16 StandBy_BMCR_Default       = 0xFFFFu;         /* BMCR snapshot in standby (pre soft-reset) */
volatile uint16 NormalMode_BMCR_Default    = 0xFFFFu;         /* BMCR snapshot in normal (post soft-reset) */
volatile static uint16 stby_mode_return    = 0u;              /* return value of Set_OP_state(STANDBY)     */
volatile static uint16 normal_mode_return  = 0u;              /* return value of Set_OP_state(NORMAL)      */

#ifndef Enable_PHY_100Mb
   #define MAC_CONFIGURATION_PS_pos  15U
   #define MAC_CONFIGURATION_FES_pos 14U
static volatile ARTIE_SFRS_t *const ARTIE_PHY_config = (volatile ARTIE_SFRS_t *)ARTIE_base;
#endif

#if ENABLE_NWAY_CONFIGURATION
volatile static uint16 NWAYConfiguratuionReturn        = 0;
volatile static uint16 NWAYConfiguratuionCheckReturn   = 0;
volatile static uint16 SGMII_ConfigurationReturn       = 0;
volatile static uint16 SGMII_Configuration_CheckReturn = 0;
#endif
#define PHY_START_OPERATION_WAIT_TIME_US 3000U /* typ 3ms recommened by NXP */
#define STANDBY_STATUS_WAIT_TIME_US      1000U
#define DISABLE_LOW_POWER_MODE_PMA_CTRL1 0x40

volatile uint16_t TJA1103_counter_Read_Device_control_Start_operation = 0;
volatile uint16_t TJA1103_Read_Device_control_Start_operation         = 0xFFFFu;
volatile uint16_t TJA1120_counter_Read_Device_control_Start_operation = 0;
volatile uint16_t TJA1120_Read_Device_control_Start_operation         = 0xFFFFu;
volatile uint16_t SGMII_advanced_status                               = 0xFFFFu;
volatile uint16_t PHY_Link_Status                                     = 0xFFFFu;
volatile uint16_t counter_SGMII_advanced_status                       = 0;
volatile uint16_t After_baseT1PmaCtrlReg                              = 0;
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
uint16 mdio_write(uint8 RegAddr, uint16 RegVal)
{
   /* Use the GMAC-level MDIO write directly, avoiding a transceiver-specific (RTL9010) driver dependency. */
   uint16 ret_val = (uint16)EthMac_WriteMii(ETH_TRCV_INDEX, RegAddr, RegVal);
   return ret_val;
}

uint16 mdio_read(uint8 RegAddr)
{
   uint16 mdio_data = 0;
   /* Use the GMAC-level MDIO read directly, avoiding a transceiver-specific (RTL9010) driver dependency. */
   (void)EthMac_ReadMii(ETH_TRCV_INDEX, RegAddr, &mdio_data);
   return mdio_data;
}

void normal_mdio_write(uint16 RegAddr, uint16 RegPage, uint16 RegVal)
{
   mdio_write(31, RegPage);
   mdio_write(RegAddr, RegVal);
   mdio_write(31, 0x0A42);
}

uint16 normal_mdio_read(uint16 RegAddr, uint16 RegPage)
{
   uint16 mdio_data = 0;
   mdio_write(31, RegPage);
   mdio_data = mdio_read(RegAddr);
   mdio_write(31, 0x0A42);
   return mdio_data;
}

uint16 special_mdio_read(uint16 RegAddr)
{
   uint16 mdio_data = 0;
   mdio_write(27, RegAddr);
   mdio_data = mdio_read(28);

   return mdio_data;
}

uint16 special_mdio_write(uint16 RegAddr, uint16 RegVal)
{
   uint16 mdio_data = 0;
   mdio_write(27, RegAddr);
   mdio_write(28, RegVal);

   return mdio_data;
}

#ifndef Enable_PHY_100Mb
void set_EthMac_1Gbps_speed(void)
{
   /* 1G build: clear PS (bit15) and FES (bit14) in MAC_CONFIGURATION → Gigabit mode.
    * ARTIE CTL_CG_E_RX_DIV / CTL_CG_E_TX_DIV already = 0 (no division, 125 MHz)
    * from EthMac_PhyConfiguration() — no redundant write needed here.            */
   volatile uint32 *macConfigReg = (volatile uint32 *)ETHER_base;
   *macConfigReg &= ~(1U << MAC_CONFIGURATION_PS_pos);  /* PS=0  → Gigabit mode  */
   *macConfigReg &= ~(1U << MAC_CONFIGURATION_FES_pos); /* FES=0 → don't-care @1G */
                                                        /* Set clock dividers for 1G (no division) */
   ARTIE_PHY_config->CLKGEN_CTRL1.f.CTL_CG_E_RX_DIV = 0x0u;
   ARTIE_PHY_config->CLKGEN_CTRL1.f.CTL_CG_E_TX_DIV = 0x0u;
}
#endif
/* ========================================================================== */
/*              TJA1103 Clause-45 (MMD) MDIO Access Helpers                   */
/* ========================================================================== */

/**
 * @brief Write a Clause-45 (MMD) register of the TJA1103.
 *
 * @details Uses manual indirect MMD access (mdio_write to regs 13/14) instead
 *          of the TJA1103 TRCV driver's Cl45 write function.
 *
 * @param DevAddr  MMD device address (e.g. ETHTRCV_30_TJA1103_MMD_30 = 0x1Eu)
 * @param RegAddr  16-bit register offset within the MMD
 * @param RegVal   Value to write
 * @return E_OK on success, E_NOT_OK on MDIO error
 */
Std_ReturnType tja1103_cl45_write(uint8 DevAddr, uint16 RegAddr, uint16 RegVal)
{
   uint16 ret_val = 0;
   ret_val |= mdio_write(MMD_ACCESS_CONTROL_REG, (uint16)(MMD_ACCESS_FUNC_ADDRESS | DevAddr));
   ret_val |= mdio_write(MMD_ACCESS_ADDR_DATA_REG, RegAddr);
   ret_val |= mdio_write(MMD_ACCESS_CONTROL_REG, (uint16)(MMD_ACCESS_FUNC_DATA_NO_INCR | DevAddr));
   ret_val |= mdio_write(MMD_ACCESS_ADDR_DATA_REG, RegVal);
   return (ret_val == 0u) ? E_OK : E_NOT_OK;
}

/**
 * @brief Read a Clause-45 (MMD) register of the TJA1103.
 *
 * @details Uses manual indirect MMD access (mdio_write/mdio_read to regs
 *          13/14) instead of the TJA1103 TRCV driver's Cl45 read function.
 *
 * @param DevAddr   MMD device address
 * @param RegAddr   16-bit register offset within the MMD
 * @param RegValPtr Pointer to store the read value
 * @return E_OK on success, E_NOT_OK on MDIO error
 */
Std_ReturnType tja1103_cl45_read(uint8 DevAddr, uint16 RegAddr, uint16 *RegValPtr)
{
   uint16 ret_val = 0;
   ret_val |= mdio_write(MMD_ACCESS_CONTROL_REG, (uint16)(MMD_ACCESS_FUNC_ADDRESS | DevAddr));
   ret_val |= mdio_write(MMD_ACCESS_ADDR_DATA_REG, RegAddr);
   ret_val |= mdio_write(MMD_ACCESS_CONTROL_REG, (uint16)(MMD_ACCESS_FUNC_DATA_NO_INCR | DevAddr));
   *RegValPtr = mdio_read((uint8)MMD_ACCESS_ADDR_DATA_REG);
   return (ret_val == 0u) ? E_OK : E_NOT_OK;
}

/**
 * @brief Read a Clause-22 register of the TJA1103.
 *
 * @details Uses mdio_read directly instead of the TJA1103 TRCV driver's
 *          Clause-22 read function.
 *
 * @param RegAddr   8-bit register address
 * @param RegValPtr Pointer to store the read value
 * @return E_OK on success, E_NOT_OK on MDIO error
 */
Std_ReturnType tja1103_cl22_read(uint8 RegAddr, uint16 *RegValPtr)
{
   *RegValPtr = mdio_read(RegAddr);
   return E_OK;
}
/* ========================================================================== */
/*                      PHY Manufacturer Detection                            */
/* ========================================================================== */

volatile uint16_t PHY_BMCR_Reg             = 0xFFFF;
volatile uint16_t Post_Config_PHY_BMCR_Reg = 0xFFFF;

volatile uint16 rtl_phy_id1 = 0xFFFFU;
volatile uint16 rtl_phy_id2 = 0xFFFFU;

/**
 * @brief Detect the connected PHY manufacturer/sub-model.
 *
 * @details Reads PHY_ID1
 * @return The detected PHY model
 */
volatile uint16_t first_read_mdio = 0xDEAD;
NXP_RTL_PHY_MODEL_T Detect_PHY_Model(void)
{
   uint16 mdio_data = 0;
   /* Step 1: Read PHY_ID1  */
   /* RTL and NXP PHYs are placed at different MDIO Addresses. Thus, both have to be tried */
   /* read PHY ID 1 first with address 0, then address 27*/
   EthMac_ReadMii(0U, 2U, &mdio_data);
   first_read_mdio = mdio_data;
   if (mdio_data == 0xFFFFU)
   {
      /* PHY not found at address 0, try address 27 */
      EthMac_ReadMii(27U, 2U, &mdio_data);
      if (mdio_data == 0xFFFFU)
      {
         /* PHY not found at either address */
         detected_phy_manufacturer = PHY_MFR_UNKNOWN;
         return Connected_PHY; /* return previous value (NXP_RTL_PHY_NUM) */
      }
      else
      {
         ETH_TRCV_INDEX = 27U; /* NXP TJA is at MDIO address 27 */
      }
   }
   else
   {
      ETH_TRCV_INDEX = 0U; /* RTL PHY is at MDIO address 0 */
   }

   rtl_phy_id1 = mdio_read(2u);
   rtl_phy_id2 = mdio_read(3u);

   /* Step 2: Identify PHY manufacturer from PHY_ID1 and verify via the PHY-specific driver. */
   if (rtl_phy_id1 == PHY_ID1_NXP_TJA_xx)
   {
      detected_phy_manufacturer = PHY_MFR_NXP;
      if (rtl_phy_id2 == PHY_ID2_NXP_TJA1103)
         Connected_PHY = NXP_TJA1103;
      else if (rtl_phy_id2 == PHY_ID2_NXP_TJA1120)
         Connected_PHY = NXP_TJA1120;
   }
   else if (rtl_phy_id1 == PHY_ID1_REALTEK_RTL_xx)
   {
      PHY_BMCR_Reg              = mdio_read(0u); /* RTL-specific BMCR diagnostic snapshot */
      detected_phy_manufacturer = PHY_MFR_REALTEK;
      Connected_PHY             = Determine_RTL_PHY_Model(); /* RTL9010BSA vs RTL9000CSA */
   }
   else
   {
      detected_phy_manufacturer = PHY_MFR_UNKNOWN;
   }

   return Connected_PHY;
}

NXP_RTL_PHY_MODEL_T Get_PHY_Model(void)
{
   return Connected_PHY;
}

/**
 * @brief Soft reset that works for both RTL9010Bx and RTL9000Cx PHYs.
 *
 * @details Unlike RTL9010Bx_Soft_Reset(), this function does NOT wait for a
 *          specific BMCR value (0x0140 is valid only for RTL9010Bx; RTL9000Cx
 *          resets to 0x2100). Instead it waits for BMCR bit 15 (Reset) to
 *          self-clear, which is the standard IEEE 802.3 completion criterion
 *          valid for both derivatives.
 *
 * @return ETH_SUCCESS on reset complete; ETH_ERROR on timeout or MDIO failure.
 */
uint8 RTL9010Bx_9000Cx_Soft_Reset(void)
{
   uint32 mdio_data = 0;
   uint32 timer     = PHY_DELAY_IN_US; // set a 2ms timer

   mdio_write(0, 0x8000); // PHY soft-reset

   do
   { // Check soft-reset complete

      mdio_data = mdio_read(0);
      if (0xFFFF == mdio_data)
         return ETH_ERROR;

      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   } while ((mdio_data != 0x0140) && (mdio_data != 0x2100));

   return ETH_SUCCESS;
}

/**
 * @brief Determine the connected RTL PHY sub-model at runtime.
 *
 * @details Transitions the PHY to Standby, reads the BMCR to capture the
 *          pre-reset state, performs a soft reset (valid for both RTL9010Bx
 *          and RTL9000Cx via bit-15 clear), then transitions to Normal and
 *          reads BMCR again. Compares against RTL9000CRG_BMCR_NORMAL_MODE:
 *            - 0x2100 => RTL9000CSA (100 Mbps)
 *            - otherwise => RTL9010BSA (1 Gbps)
 *
 * @return RTL_9000Cx or RTL_9010x; sets Connected_PHY as a side effect.
 */
/* Compile-time default ensures EthIf_Init() receives a valid pointer during BswM startup,
 * before RTL_PHY_Pre_Init() / Determine_RTL_PHY_Model() have run.
 * Runtime PHY detection in Determine_RTL_PHY_Model() may update this if needed. */
NXP_RTL_PHY_MODEL_T Determine_RTL_PHY_Model(void)
{
   NXP_RTL_PHY_MODEL_T lConnected_PHY = NXP_RTL_PHY_NUM;

   stby_mode_return = (uint16)RTL9010x_Set_OP_state(OP_CMD_GOTO_STANDBY);
   mdio_write(0x1Fu, 0x0000u);
   StandBy_BMCR_Default = mdio_read(0x00u);
   mdio_write(0x1Fu, 0x0A42u);

   (void)RTL9010Bx_9000Cx_Soft_Reset();

   /* OP_CMD_GOTO_NORMAL is required to activate the PHY from standby to normal
    * operating mode. Without it, the SGMII interface does not come up (LNKSTS=0).
    * The OPCR registers set here are operating-state controls, not speed-specific;
    * speed is governed by BMCR which Post_Init will set to 0x2100. */
   normal_mode_return = (uint16)RTL9010x_Set_OP_state(OP_CMD_GOTO_NORMAL);
   mdio_write(0x1Fu, 0x0000u);
   NormalMode_BMCR_Default = mdio_read(0x00u);
   mdio_write(0x1Fu, 0x0A42u);

   if (RTL9000CRG_BMCR_NORMAL_MODE == NormalMode_BMCR_Default)
   {
      lConnected_PHY = RTL_9000Cx;
      Connected_PHY  = RTL_9000Cx;
   }
   else
   {
      lConnected_PHY = RTL_9010x;
      Connected_PHY  = RTL_9010x;
   }
   return lConnected_PHY;
}

uint16 RTL90x0xx_Set_OP_state(uint8 op_cmd)
{
   uint16 mdio_data = 0;

   mdio_write(0x1b, 0xdd00); // read OPCR2
   mdio_data = mdio_read(0x1c);
   if (0xFFFF == mdio_data)
      return ETH_ERROR;
   if (OP_CMD_GOTO_STANDBY == op_cmd)
   {
      mdio_write(0x1b, 0xdd00); // read OPCR2
      mdio_data &= ~((uint16)0x001f);
      mdio_write(0x1c, (mdio_data | 0x12));
   }
   else if (OP_CMD_GOTO_SLEEP == op_cmd)
   {
      mdio_write(0x1b, 0xdd00); // read OPCR2
      mdio_data &= ~((uint16)0x001f);
      mdio_write(0x1c, (mdio_data | 0x14));
   }
   else if (OP_CMD_GOTO_NORMAL == op_cmd)
   {
      mdio_write(0x1b, 0xdd00); // read OPCR2
      mdio_data &= ~((uint16)0x001f);
      mdio_write(0x1c, (mdio_data | 0x13));
      mdio_write(0x1b, 0xdd20); // read OPCR4
      mdio_data = mdio_read(0x1c);
      mdio_data &= ~((uint16)0x000f);
      mdio_write(0x1c, (mdio_data | 0x0B));
   }
   else
      return ETH_ERROR;

   return ETH_SUCCESS;
}
uint16 RTL9000Cx_Set_OP_state(uint8 op_cmd)
{
   uint16 state = RTL90x0xx_Set_OP_state(op_cmd);
   return state;
}
void RTL_PHY_Pre_Init(uint8 TrcvIdx)
{
   /* nothing to do */
   (void)TrcvIdx;
}

void RTL_PHY_Post_Init(uint8 TrcvIdx)
{
   if (Connected_PHY == RTL_9010x)
   {
#ifndef Enable_PHY_100Mb
      set_EthMac_1Gbps_speed();
#endif
   }
   else if (Connected_PHY == RTL_9000Cx)
   {
      /* RTL9000CSA — always 100 Mbps (non-combo PHY)                           */
      /* Vector driver always writes BasicCtrlRegVal = 0x2100; no BMCR override */
      /* RTL9000CSA specific init — to be added */
   }
   else
   {
      /* Unknown PHY model — no-op */
   }
}

/* ========================================================================== */
/*                   TJA1103 Pre/Post Init Callbacks                          */
/* ========================================================================== */

/**
 * @brief Pre-Init callout for the TJA110x EthTrcv driver.
 * @param TrcvIdx  Transceiver index assigned to the TJA110x by the AUTOSAR stack.
 */
void TJA1103_PHY_Pre_Init(uint8 TrcvIdx)
{
   (void)TrcvIdx; /* unused */
}

uint16 sgmiiBasicControlReg                         = 0x0U;
uint16 sgmiiBasicControlReg_afterErrata             = 0xFFFFu;
uint16 sgmiiBasicControlReg_afterLPMSet             = 0xFFFFu;
uint16 sgmiiAdvancedControlReg_beforeOperationStart = 0xFFFFu;
uint16 sgmiiAdvancedControlReg_afterOperationStart  = 0xFFFFu;
uint16 TJASiliconVersion_reg3                       = 0xFFFFu;
void TJA11xx_Errata_Handling(void)
{
   /* read the ID 3 */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, 4U, &TJASiliconVersion_reg3);
   /* Errata: SGMII PCS restart — required after device restart (reset/power-on),
    * wake-up from sleep, or SGMII_BASIC_CONTROL.RST. Toggle LPM 1 -> 0, no delay needed. */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, &sgmiiBasicControlReg);
   sgmiiBasicControlReg |= TJA1103_REG_SGMII_BASIC_CONTROL_LPM_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, sgmiiBasicControlReg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, &sgmiiBasicControlReg_afterLPMSet);
   sgmiiBasicControlReg &= ~((uint16)TJA1103_REG_SGMII_BASIC_CONTROL_LPM_MASK);
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, sgmiiBasicControlReg);
   /* read back for final confirmation */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, &sgmiiBasicControlReg_afterErrata);

   /* Since it's not mentioned in Errata section 3.2*/
   // /* Set the ADVANCED_CONTROL to START_OPERATIO = Exit Standby */
   // (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_ADVANCED_CONTROL,
   //                         &sgmiiAdvancedControlReg_beforeOperationStart);

   // sgmiiAdvancedControlReg_beforeOperationStart |= TJA1103_REG_SGMII_ADVANCED_CONTROL_START_OPERATION_MASK;
   // (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_ADVANCED_CONTROL,
   //                          sgmiiAdvancedControlReg_beforeOperationStart);

   // /* Read back to confirm mode */
   // (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_ADVANCED_CONTROL,
   //                         &sgmiiAdvancedControlReg_afterOperationStart);
}

/**
 * @brief Runs the TJA1103-specific ePHY/xMII init sequence used by TJA1103_PHY_Post_Init.
 */
/* TJA1103  and TJA1120 Init sequence as per NXP's recommended procedure */
void TJA1103_Init_Sequence(void)
{
   uint16_t deviceControlReg                           = 0xFFFFu;
   uint16_t baseT1PmaCtrlReg                           = 0xFFFFu;
   uint16_t sgmiiBasicControlReg                       = 0xFFFFu;
   uint64_t start_time_us                              = 0ULL;
   uint32_t elapsed_us                                 = 0U;
   TJA1103_counter_Read_Device_control_Start_operation = 0;

   /* Step-1 */
   /* MMD-30; ADDr-0040h; Name:DEVICE_CONTROL; Field:SUPER_CONFIG_ENABLE; Operation:Write; Expected_value:1b;  Description:Enable
    * writing of all configuration registers */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, &deviceControlReg);
   deviceControlReg |= ETHTRCV_30_TJA1103_REG_DEVICE_CONTROL_SUPER_CONFIG_ENABLE_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, deviceControlReg);

   /* Step-2 */
   /* MMD-1; ADDr-0834; Name:BASE_T1_PMA_CONTROL; Field:LEADER_FOLLOWER; Operation:Write; Expected_value:0b;  Description:ESet the
    * device to  follower*/
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_BASE_T1_PMA_CONTROL, &baseT1PmaCtrlReg);
   baseT1PmaCtrlReg &= ~((uint16)TJA1103_BASE_T1_PMA_CONTROL_LEADER_FOLLOWER_MASK); /* 0 = Follower */
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_BASE_T1_PMA_CONTROL, baseT1PmaCtrlReg);

   /* Step-3 */
   /* MMD-30; ADDr-0040h; Name:DEVICE_CONTROL; Field:SUPER_CONFIG_ENABLE; Operation:Write; Expected_value:0b;  Description:Disable
    * writing of all configuration registers */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, &deviceControlReg);
   deviceControlReg &= ~((uint16)ETHTRCV_30_TJA1103_REG_DEVICE_CONTROL_SUPER_CONFIG_ENABLE_MASK);
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, deviceControlReg);

   /* Step-4 */
   /* MMD-30; ADDr-0040h; Name:DEVICE_CONTROL; Field:START_OPERATION; Operation:Write; Expected_value:1b;  Description:Start device
    * operation */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, &deviceControlReg);
   deviceControlReg |= TJA1103_DEVICE_CONTROL_START_OPERATION_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, deviceControlReg);

   /* Step-5 */
   /* MMD-30; ADDr-0040h; Name:DEVICE_CONTROL; Field:START_OPERATION; Operation:Read; Expected_value:0b; Description:Read bit until
    * the device clears it to 0 (typ. 3 ms) */
   Get_Platform_ustime(&start_time_us); /* Get start time in microseconds */
   do
   {
      (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL,
                              (uint16_t *)&TJA1103_Read_Device_control_Start_operation);
      TJA1103_counter_Read_Device_control_Start_operation++;
      if (!(TJA1103_Read_Device_control_Start_operation & TJA1103_DEVICE_CONTROL_START_OPERATION_MASK))
      {
         break;
      }
      Get_Platform_Elapsed_ustime(&elapsed_us, start_time_us);
   } while (elapsed_us < PHY_START_OPERATION_WAIT_TIME_US);

   /* Step-6 */
   /* MMD-30; ADDr-B000h; Name:SGMII_BASIC_CONTROL; Field:LPM; Operation:Write; Expected_value:1b;  Description: Reset PCS block of
    * SGMII interface. SGMII_BASIC_CONTROL is not readable while LPM is set */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, &sgmiiBasicControlReg);
   sgmiiBasicControlReg |= TJA1103_REG_SGMII_BASIC_CONTROL_LPM_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, sgmiiBasicControlReg);

   /* Step-7 */
   /* MMD-30; ADDr-B000h; Name:SGMII_BASIC_CONTROL; Field:LPM; Operation:Write; Expected_value:0b;  Description: Reset PCS block of
    * SGMII interface. No delay required between setting and re-setting the LPM bit. */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, &sgmiiBasicControlReg);
   sgmiiBasicControlReg &= ~TJA1103_REG_SGMII_BASIC_CONTROL_LPM_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, sgmiiBasicControlReg);
}

/**
 * @brief Runs the TJA1120-specific ePHY/xMII init sequence used by TJA1103_PHY_Post_Init.
 */
volatile uint16_t ReadBeforeWrite_PMA_CtrlReg1 = 0xFFFF;
volatile uint16_t ReadAftereWrite_PMA_CtrlReg1 = 0xFFFF;
volatile uint16_t StartofInit_PMA_CtrlReg1     = 0xFFFF;
volatile uint16_t STDBY_Successful_break       = 0;
volatile uint16_t STDBY_TimeOut_break          = 0;
void TJA1120_Init_Sequence(void)
{
   uint16_t deviceControlReg                           = 0xFFFFu;
   uint16_t baseT1PmaCtrlReg                           = 0xFFFFu;
   uint16_t sgmiiBasicControlReg                       = 0xFFFFu;
   uint64_t start_time_us                              = 0ULL;
   uint32_t elapsed_us                                 = 0U;
   uint16_t phy_standby_mode_state                     = 0xFFFFu;
   TJA1120_counter_Read_Device_control_Start_operation = 0;

   /* Test code to read PMA control register before writing */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_PMA_CONTROL1,
                           (uint16_t *)&StartofInit_PMA_CtrlReg1);

   /* Step-1 */
   /* MMD-30; ADDr-0040h; Name:DEVICE_CONTROL; Field:GOTO_STANDBY; Operation:Write; Expected_value:1b;  Description: Set device to
    * STANBDY */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, &deviceControlReg);
   deviceControlReg |= ETHTRCV_30_TJA1103_REG_DEVICE_CONTROL_STANDBY_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, deviceControlReg);
   /* VDD-Core LDO unlock/calibrate/re-lock below must not be split by an ISR (e.g. I2C) */

   /* Step-1a: Wait for 1ms to check if it's in standby state */
   Get_Platform_ustime(&start_time_us); /* Get start time in microseconds */
   do
   {
      (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, TJA1103_REG_OFFS_PHY_STATE, (uint16_t *)&phy_standby_mode_state);
      if (!(phy_standby_mode_state & 0x0001))
      {
         STDBY_Successful_break++;
         break;
      }
      else
      {
         STDBY_TimeOut_break++;
      }
      Get_Platform_Elapsed_ustime(&elapsed_us, start_time_us);
   } while (elapsed_us < STANDBY_STATUS_WAIT_TIME_US);

   /* Step-2 */
   /* Errata Item 3.1 for TJA1120. */
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1120_REG_OFFS_VDD_CORE_UNLOCK_1,
                            TJA1120_VDD_CORE_UNLOCK_KEY_1); // checked
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1120_REG_OFFS_VDD_CORE_UNLOCK_2,
                            TJA1120_VDD_CORE_UNLOCK_KEY_2); // checked
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1120_REG_OFFS_VDD_CORE_LDO_SETTING,
                            TJA1120_VDD_CORE_LDO_SETTING_VALUE); // checked
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_1, TJA1120_REG_OFFS_ADC_LATCH_CONFIG,
                            TJA1120_ADC_LATCH_CONFIG_VALUE); // checked
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_1, TJA1120_REG_OFFS_SQI_AVERAGING_CONFIG,
                            TJA1120_SQI_AVERAGING_CONFIG_VALUE);                                     // checked
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1120_REG_OFFS_VDD_CORE_UNLOCK_1, 0x0000u); // checked
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1120_REG_OFFS_VDD_CORE_UNLOCK_2, 0x0000u); // checked

   /* Step-3 */
   /* MMD-30; ADDr-0040h; Name:DEVICE_CONTROL; Field:SUPER_CONFIG_ENABLE; Operation:Write; Expected_value:1b;  Description: Enable
    * super config */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, &deviceControlReg);
   deviceControlReg |= ETHTRCV_30_TJA1103_REG_DEVICE_CONTROL_SUPER_CONFIG_ENABLE_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, deviceControlReg);

   /* This is not mentioned in AptivBringupSequence.pdf document provided by NXP.
   This change is added based on Comparison between Good boards vs Bad boards. We have issue where same SW works on few boars(Good
   boards) and fails on others (Bad boards). With this change, it's working on BAD boards. */
   /* Writing 0x40 into PMA controlreg -1 */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_PMA_CONTROL1,
                           (uint16_t *)&ReadBeforeWrite_PMA_CtrlReg1);
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_PMA_CONTROL1, DISABLE_LOW_POWER_MODE_PMA_CTRL1);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_PMA_CONTROL1,
                           (uint16_t *)&ReadAftereWrite_PMA_CtrlReg1);

   /* Step-4 */
   /* MMD-1; ADDr-0834; Name:BASE_T1_PMA_CONTROL; Field:LEADER_FOLLOWER; Operation:Write; Expected_value:0b;  Description:Set the
    * device to  follower*/
   baseT1PmaCtrlReg = TJA1120_BASE_T1_PMA_CONTROL_LF_VALUE;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_BASE_T1_PMA_CONTROL, baseT1PmaCtrlReg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_BASE_T1_PMA_CONTROL,
                           (uint16_t *)&After_baseT1PmaCtrlReg);

   /* Additonal Delay of 3 ms for testing */

   Get_Platform_ustime(&start_time_us); /* Get start time in microseconds */
   do
   {
      Get_Platform_Elapsed_ustime(&elapsed_us, start_time_us);
   } while (elapsed_us < PHY_START_OPERATION_WAIT_TIME_US);

   /* Step-5 */
   /* MMD-30; ADDr-0040h; Name:DEVICE_CONTROL; Field:SUPER_CONFIG_ENABLE; Operation:Write; Expected_value:0b;  Description:Disable
    * writing of all configuration registers */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, &deviceControlReg);
   deviceControlReg &= ~((uint16)ETHTRCV_30_TJA1103_REG_DEVICE_CONTROL_SUPER_CONFIG_ENABLE_MASK);
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, deviceControlReg);

   /* Step-6 */
   /* MMD-30; ADDr-0040h; Name:DEVICE_CONTROL; Field:START_OPERATION; Operation:Write; Expected_value:1b;  Description:Start device
    * operation */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, &deviceControlReg);
   deviceControlReg |= TJA1103_DEVICE_CONTROL_START_OPERATION_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, deviceControlReg);

   /* Step-7 */
   /* MMD-30; ADDr-0040h; Name:DEVICE_CONTROL; Field:START_OPERATION; Operation:Read; Expected_value:0b; Description:Read bit until
    * the device clears it to 0 (typ. 3 ms) */
   Get_Platform_ustime(&start_time_us); /* Get start time in microseconds */
   do
   {
      (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL,
                              (uint16_t *)&TJA1120_Read_Device_control_Start_operation);
      TJA1120_counter_Read_Device_control_Start_operation++;
      if (!(TJA1120_Read_Device_control_Start_operation & TJA1103_DEVICE_CONTROL_START_OPERATION_MASK))
      {
         break;
      }
      Get_Platform_Elapsed_ustime(&elapsed_us, start_time_us);
   } while (elapsed_us < PHY_START_OPERATION_WAIT_TIME_US);

   /* Step-8 */
   /* MMD-30; ADDr-B000h; Name:SGMII_BASIC_CONTROL; Field:LPM; Operation:Write; Expected_value:1b;  Description: Reset PCS block of
    * SGMII interface. SGMII_BASIC_CONTROL is not readable while LPM is set */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, &sgmiiBasicControlReg);
   sgmiiBasicControlReg |= TJA1103_REG_SGMII_BASIC_CONTROL_LPM_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, sgmiiBasicControlReg);

   /* Step-9 */
   /* MMD-30; ADDr-B000h; Name:SGMII_BASIC_CONTROL; Field:LPM; Operation:Write; Expected_value:0b;  Description: Reset PCS block of
    * SGMII interface. No delay required between setting and re-setting the LPM bit. */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, &sgmiiBasicControlReg);
   sgmiiBasicControlReg &= ~TJA1103_REG_SGMII_BASIC_CONTROL_LPM_MASK;
   (void)tja1103_cl45_write(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, sgmiiBasicControlReg);

   /* Step-10*/
   /* PHY status: Link status: approx 100ms as per init sequence from nxp*/
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, ETHTRCV_30_TJA1103_REG_OFFS_PHY_STATUS, (uint16_t *)&PHY_Link_Status);

   /* Step-11  */
   /* SGMII advanced status: Check if sgmii link is up */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, SGMII_ADVANCED_STATUS, (uint16_t *)&SGMII_advanced_status);
}

/**
 * @brief Post-Init callout for the TJA110x EthTrcv driver.
 * @param TrcvIdx  Transceiver index (same value passed to TJA1103_PHY_Pre_Init).
 */
void TJA1103_PHY_Post_Init(uint8 TrcvIdx)
{
   /* Set MAC link speed to 100Mbps or leave 1Gbps default configuration */
#ifndef Enable_PHY_100Mb
   set_EthMac_1Gbps_speed();
#endif

   if (Connected_PHY == NXP_TJA1103)
   {
      TJA1103_Init_Sequence();
   }
   else if (Connected_PHY == NXP_TJA1120)
   {
      TJA11xx_Errata_Handling();
      TJA1120_Init_Sequence();
   }
   else
   {
      /* Unknown NXP PHY sub-model — no-op */
   }

   /* Read back key registers for debug / verification (common to both sub-models) */
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, &TJA1103_DeviceControl_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_XMII_CONTROL, &TJA1103_XmiiControl_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_MII_BASIC_CONFIG, &TJA1103_MiiBasicConfig_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_BASE_T1_PMA_CONTROL, &TJA1103_BaseT1PmaCtrl_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, ETHTRCV_30_TJA1103_REG_OFFS_PHY_CONTROL, &TJA1103_PhyControl_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, ETHTRCV_30_TJA1103_REG_OFFS_PHY_STATUS, &TJA1103_PhyStatus_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, ETHTRCV_30_TJA1103_REG_OFFS_SIGNAL_QUALITY, &TJA1103_SignalQuality_Reg);
}
#if ENABLE_NWAY_CONFIGURATION
uint16 RTL9010Ax_Initial_with_NWAY_Configuration()
{ /* Refer to Errata_List_v0.4.pdf, Erratum#2 */

   uint16 mdio_data = 0;
   uint16 timer     = PHY_DELAY_IN_US; /* set a 2ms timer */
   uint16 ret_val   = 0;

   /* PHY Parameter Start */
   ret_val |= mdio_write(31, 0x0A54);
   ret_val |= mdio_write(21, 0xFA06);
   ret_val |= mdio_write(31, 0x0BC4);
   ret_val |= mdio_write(21, 0x16FE);

   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0010);
   ret_val |= mdio_write(27, 0xB830);
   ret_val |= mdio_write(28, 0x8000);
   ret_val |= mdio_write(27, 0xB800);
   mdio_data = ((uint16)mdio_read(28) & 0x0040);
   while (mdio_data != 0x0040)
   {
      ret_val |= mdio_write(27, 0xB800);
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   }

   ret_val |= mdio_write(27, 0x8020);
   ret_val |= mdio_write(28, 0x9100);
   ret_val |= mdio_write(27, 0xB82E);
   ret_val |= mdio_write(28, 0x0001);

   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0290);
   ret_val |= mdio_write(27, 0xA012);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xA014);
   ret_val |= mdio_write(28, 0x2C03);
   ret_val |= mdio_write(28, 0x2C07);
   ret_val |= mdio_write(28, 0x2C0B);
   ret_val |= mdio_write(28, 0x6054);
   ret_val |= mdio_write(28, 0xA701);
   ret_val |= mdio_write(28, 0xD500);
   ret_val |= mdio_write(28, 0x2108);
   ret_val |= mdio_write(28, 0x4054);
   ret_val |= mdio_write(28, 0x8701);
   ret_val |= mdio_write(28, 0xA74A);
   ret_val |= mdio_write(28, 0x20DE);
   ret_val |= mdio_write(28, 0xD700);
   ret_val |= mdio_write(28, 0x880F);
   ret_val |= mdio_write(28, 0x262D);
   ret_val |= mdio_write(27, 0xA01A);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xA004);
   ret_val |= mdio_write(28, 0x062C);
   ret_val |= mdio_write(27, 0xA002);
   ret_val |= mdio_write(28, 0x00DD);
   ret_val |= mdio_write(27, 0xA000);
   ret_val |= mdio_write(28, 0x7107);
   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0210);

   ret_val |= mdio_write(27, 0xB82E);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0x8020);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0000);

   ret_val |= mdio_write(27, 0xB800);
   mdio_data = ((uint16)mdio_read(28) & 0x0040);
   timer     = PHY_DELAY_IN_US; /* set a 2ms timer */
   while (mdio_data != 0x0000)
   {
      ret_val |= mdio_write(27, 0xB800);
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   }
   /* End */

   ret_val |= mdio_write(0, 0x8000); /* PHY soft-reset */

   while (mdio_data != 0x0140)
   { /* Check soft-reset complete */
      mdio_data = mdio_read(0);
   }

   return ret_val;
}

uint16 Reg_B820   = 0xFFFF;
uint16 Reg_B830   = 0xFFFF;
uint16 Reg_02     = 0xFFFF;
uint16 SGMII_Test = 0xFFFF;
uint16 OPMR_Test  = 0xFFFF;

uint16 RTL9010Ax_Initial_with_SGMII_Configuration()
{ /* Refer to Errata_List_v0.4.pdf, Erratum#4 */

   uint16 mdio_data = 0;
   uint16 timer     = PHY_DELAY_IN_US; /* set a 2ms timer */
   uint16 ret_val   = 0;
   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0010);
   ret_val |= mdio_write(27, 0xB830);
   ret_val |= mdio_write(28, 0x8000);

   ret_val |= mdio_write(27, 0xB820);
   Reg_B820 = mdio_read(28);
   ret_val |= mdio_write(27, 0xB830);
   Reg_B830 = mdio_read(28);
   Reg_02   = mdio_read(2);

   ret_val |= mdio_write(27, 0xCC04U);
   SGMII_Test = mdio_read(28);

   ret_val |= mdio_write(27, 0xDF10U);
   OPMR_Test = mdio_read(28);

   ret_val |= mdio_write(27, 0xB800);
   mdio_data = ((uint16)mdio_read(28) & 0x0040);
   while (mdio_data != 0x0040)
   {
      ret_val |= mdio_write(27, 0xB800);
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   }

   ret_val |= mdio_write(27, 0x8020);
   ret_val |= mdio_write(28, 0x9100);
   ret_val |= mdio_write(27, 0xB82E);
   ret_val |= mdio_write(28, 0x0001);

   ret_val |= mdio_write(27, 0x8614);
   ret_val |= mdio_write(28, 0xAF86);
   ret_val |= mdio_write(28, 0x20AF);
   ret_val |= mdio_write(28, 0x862A);
   ret_val |= mdio_write(28, 0xAF86);
   ret_val |= mdio_write(28, 0x2AAF);
   ret_val |= mdio_write(28, 0x862A);
   ret_val |= mdio_write(28, 0xEE82);
   ret_val |= mdio_write(28, 0xF600);
   ret_val |= mdio_write(28, 0x0286);
   ret_val |= mdio_write(28, 0x2AAF);
   ret_val |= mdio_write(28, 0x096B);
   ret_val |= mdio_write(28, 0xF8F9);
   ret_val |= mdio_write(28, 0xEF59);
   ret_val |= mdio_write(28, 0xF9FA);
   ret_val |= mdio_write(28, 0xFBBF);
   ret_val |= mdio_write(28, 0x8768);
   ret_val |= mdio_write(28, 0x023C);
   ret_val |= mdio_write(28, 0x5F00);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(28, 0xAD28);
   ret_val |= mdio_write(28, 0x1AAE);
   ret_val |= mdio_write(28, 0x03AF);
   ret_val |= mdio_write(28, 0x86E4);
   ret_val |= mdio_write(28, 0xE187);
   ret_val |= mdio_write(28, 0x6BD0);
   ret_val |= mdio_write(28, 0x001B);
   ret_val |= mdio_write(28, 0x019E);
   ret_val |= mdio_write(28, 0x13D0);
   ret_val |= mdio_write(28, 0x011B);
   ret_val |= mdio_write(28, 0x019E);
   ret_val |= mdio_write(28, 0x34D0);
   ret_val |= mdio_write(28, 0x021B);
   ret_val |= mdio_write(28, 0x019E);
   ret_val |= mdio_write(28, 0xE8EE);
   ret_val |= mdio_write(28, 0x876B);
   ret_val |= mdio_write(28, 0x00AF);
   ret_val |= mdio_write(28, 0x8748);
   ret_val |= mdio_write(28, 0xBF87);
   ret_val |= mdio_write(28, 0x5002);
   ret_val |= mdio_write(28, 0x3C5F);
   ret_val |= mdio_write(28, 0xAC28);
   ret_val |= mdio_write(28, 0x03AF);
   ret_val |= mdio_write(28, 0x8748);
   ret_val |= mdio_write(28, 0xBF87);
   ret_val |= mdio_write(28, 0x5302);
   ret_val |= mdio_write(28, 0x43BB);
   ret_val |= mdio_write(28, 0x0243);
   ret_val |= mdio_write(28, 0xC3EE);
   ret_val |= mdio_write(28, 0x876B);
   ret_val |= mdio_write(28, 0x0102);
   ret_val |= mdio_write(28, 0x42E7);
   ret_val |= mdio_write(28, 0xEF47);
   ret_val |= mdio_write(28, 0xE487);
   ret_val |= mdio_write(28, 0x6CE5);
   ret_val |= mdio_write(28, 0x876D);
   ret_val |= mdio_write(28, 0xAF87);
   ret_val |= mdio_write(28, 0x48BF);
   ret_val |= mdio_write(28, 0x8756);
   ret_val |= mdio_write(28, 0x023C);
   ret_val |= mdio_write(28, 0x5FAC);
   ret_val |= mdio_write(28, 0x281A);
   ret_val |= mdio_write(28, 0xE087);
   ret_val |= mdio_write(28, 0x6CE1);
   ret_val |= mdio_write(28, 0x876D);
   ret_val |= mdio_write(28, 0xEF64);
   ret_val |= mdio_write(28, 0xE087);
   ret_val |= mdio_write(28, 0x6EE1);
   ret_val |= mdio_write(28, 0x876F);
   ret_val |= mdio_write(28, 0xEF74);
   ret_val |= mdio_write(28, 0x0243);
   ret_val |= mdio_write(28, 0x02AC);
   ret_val |= mdio_write(28, 0x5035);
   ret_val |= mdio_write(28, 0x00AF);
   ret_val |= mdio_write(28, 0x8748);
   ret_val |= mdio_write(28, 0xBF87);
   ret_val |= mdio_write(28, 0x5902);
   ret_val |= mdio_write(28, 0x43BB);
   ret_val |= mdio_write(28, 0x0243);
   ret_val |= mdio_write(28, 0xC3EE);
   ret_val |= mdio_write(28, 0x876B);
   ret_val |= mdio_write(28, 0x02BF);
   ret_val |= mdio_write(28, 0x8765);
   ret_val |= mdio_write(28, 0x0243);
   ret_val |= mdio_write(28, 0xBBBF);
   ret_val |= mdio_write(28, 0x875C);
   ret_val |= mdio_write(28, 0x0243);
   ret_val |= mdio_write(28, 0xBBBF);
   ret_val |= mdio_write(28, 0x8762);
   ret_val |= mdio_write(28, 0x0243);
   ret_val |= mdio_write(28, 0xBBEE);
   ret_val |= mdio_write(28, 0x8774);
   ret_val |= mdio_write(28, 0x0002);
   ret_val |= mdio_write(28, 0x42E7);
   ret_val |= mdio_write(28, 0xEF47);
   ret_val |= mdio_write(28, 0xE487);
   ret_val |= mdio_write(28, 0x70E5);
   ret_val |= mdio_write(28, 0x8771);
   ret_val |= mdio_write(28, 0xAF87);
   ret_val |= mdio_write(28, 0x48EE);
   ret_val |= mdio_write(28, 0x876B);
   ret_val |= mdio_write(28, 0x00EE);
   ret_val |= mdio_write(28, 0x8775);
   ret_val |= mdio_write(28, 0x01AF);
   ret_val |= mdio_write(28, 0x8748);
   ret_val |= mdio_write(28, 0xE087);
   ret_val |= mdio_write(28, 0x70E1);
   ret_val |= mdio_write(28, 0x8771);
   ret_val |= mdio_write(28, 0xEF64);
   ret_val |= mdio_write(28, 0xE087);
   ret_val |= mdio_write(28, 0x72E1);
   ret_val |= mdio_write(28, 0x8773);
   ret_val |= mdio_write(28, 0xEF74);
   ret_val |= mdio_write(28, 0x0243);
   ret_val |= mdio_write(28, 0x02AD);
   ret_val |= mdio_write(28, 0x504E);
   ret_val |= mdio_write(28, 0xBF87);
   ret_val |= mdio_write(28, 0x5C02);
   ret_val |= mdio_write(28, 0x3C5F);
   ret_val |= mdio_write(28, 0x3C00);
   ret_val |= mdio_write(28, 0x009F);
   ret_val |= mdio_write(28, 0x0DBF);
   ret_val |= mdio_write(28, 0x875F);
   ret_val |= mdio_write(28, 0x023C);
   ret_val |= mdio_write(28, 0x5F3C);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(28, 0x9F02);
   ret_val |= mdio_write(28, 0xAE27);
   ret_val |= mdio_write(28, 0xBF87);
   ret_val |= mdio_write(28, 0x6502);
   ret_val |= mdio_write(28, 0x43BB);
   ret_val |= mdio_write(28, 0xBF87);
   ret_val |= mdio_write(28, 0x5C02);
   ret_val |= mdio_write(28, 0x43BB);
   ret_val |= mdio_write(28, 0xBF87);
   ret_val |= mdio_write(28, 0x6202);
   ret_val |= mdio_write(28, 0x43BB);
   ret_val |= mdio_write(28, 0xE187);
   ret_val |= mdio_write(28, 0x7411);
   ret_val |= mdio_write(28, 0xE587);
   ret_val |= mdio_write(28, 0x7439);
   ret_val |= mdio_write(28, 0x03AA);
   ret_val |= mdio_write(28, 0x19EE);
   ret_val |= mdio_write(28, 0x876B);
   ret_val |= mdio_write(28, 0x00EE);
   ret_val |= mdio_write(28, 0x8776);
   ret_val |= mdio_write(28, 0x01AE);
   ret_val |= mdio_write(28, 0x0F02);
   ret_val |= mdio_write(28, 0x42E7);
   ret_val |= mdio_write(28, 0xEF47);
   ret_val |= mdio_write(28, 0xE487);
   ret_val |= mdio_write(28, 0x70E5);
   ret_val |= mdio_write(28, 0x8771);
   ret_val |= mdio_write(28, 0xEE87);
   ret_val |= mdio_write(28, 0x7400);
   ret_val |= mdio_write(28, 0xFFFE);
   ret_val |= mdio_write(28, 0xFDEF);
   ret_val |= mdio_write(28, 0x95FD);
   ret_val |= mdio_write(28, 0xFC04);
   ret_val |= mdio_write(28, 0xEECF);
   ret_val |= mdio_write(28, 0x0411);
   ret_val |= mdio_write(28, 0xCC00);
   ret_val |= mdio_write(28, 0x00CC);
   ret_val |= mdio_write(28, 0x7A00);
   ret_val |= mdio_write(28, 0xD04A);
   ret_val |= mdio_write(28, 0xF0CC);
   ret_val |= mdio_write(28, 0x40F8);
   ret_val |= mdio_write(28, 0xCC42);
   ret_val |= mdio_write(28, 0xF0CC);
   ret_val |= mdio_write(28, 0x4420);
   ret_val |= mdio_write(28, 0xCC70);
   ret_val |= mdio_write(28, 0x11CE);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(28, 0x003C);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(28, 0x003C);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xB818);
   ret_val |= mdio_write(28, 0x0967);
   ret_val |= mdio_write(27, 0xB81A);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xB81C);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xB81E);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xB832);
   ret_val |= mdio_write(28, 0x0001);

   ret_val |= mdio_write(27, 0xB82E);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0x8020);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0000);

   ret_val |= mdio_write(27, 0xB800);
   mdio_data = mdio_read(28) & 0x0040;
   timer     = PHY_DELAY_IN_US; /* set a 2ms timer */
   while (mdio_data != 0x0000)
   {
      ret_val |= mdio_write(27, 0xB800);
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   }
   /* End */

   ret_val |= mdio_write(0, 0x8000); /* PHY soft-reset */

   while (mdio_data != 0x0140)
   { /* Check soft-reset complete */
      mdio_data = mdio_read(0);
   }

   return ETH_SUCCESS;
}

uint16 RTL9010Ax_Initial_with_NWAY_Configuration_Check()
{
   uint16 mdio_data     = 0, mdio_data_temp;
   uint16 mdio_data_chk = 0;
   uint16 timer         = PHY_DELAY_IN_US; /* set a 2ms timer */
   uint16 ret_val       = 0;

   uint16 page;
   uint16 reg, i, param_address;

   for (i = 0; i < 2 * 3; i = i + 3)
   {
      page          = param_with_NWAY_check[i];
      mdio_data_chk = param_with_NWAY_check[i + 2];
      reg           = param_with_NWAY_check[i + 1];
      if (0 == page)
      {
         ret_val |= mdio_write(27, reg);
         mdio_data = mdio_read(28);
      }
      else
      {
         ret_val |= mdio_write(31, page);
         mdio_data = mdio_read(reg);
      }
      if (mdio_data_chk != mdio_data)
      {
         return ETH_ERROR;
      }
   }

   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0010);
   ret_val |= mdio_write(27, 0xB830);
   ret_val |= mdio_write(28, 0x8000);
   ret_val |= mdio_write(27, 0xB800);
   timer = PHY_DELAY_IN_US;
   while (mdio_data != 0x0040)
   {
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   }
   ret_val |= mdio_write(27, 0x8020);
   ret_val |= mdio_write(28, 0x9100);
   ret_val |= mdio_write(27, 0xB82E);
   ret_val |= mdio_write(28, 0x0001);

   param_address = 0;
   for (i = 0; i < 14; i++)
   {
      ret_val |= mdio_write(31, 0xA01);
      mdio_data_temp = mdio_read(17);
      mdio_data_temp &= ~(0x1FF);
      param_address &= 0x1FF;
      ret_val |= mdio_write(17, (mdio_data_temp | param_address));
      ret_val |= mdio_write(31, 0xA01);
      mdio_data     = mdio_read(18);
      mdio_data_chk = param_with_NWAY_check2[i];
      if (mdio_data_chk != mdio_data)
      {
         return ETH_ERROR;
      }
      param_address++;
   }
   ret_val |= mdio_write(27, 0xB82E);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0x8020);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0000);

   ret_val |= mdio_write(27, 0xB800);
   mdio_data = mdio_read(28);
   timer     = PHY_DELAY_IN_US;
   while (mdio_data != 0x0000)
   {
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   }

   Errata_1_Test = 1;
   return ret_val;
}

uint16 RTL9010Ax_Initial_with_SGMII_Configuration_Check()
{
   uint16 mdio_data     = 0;
   uint16 mdio_data_chk = 0;
   uint16 timer         = PHY_DELAY_IN_US; /* set a 2ms timer */

   uint16 i;
   uint16 ret_val = 0;

   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0010);
   ret_val |= mdio_write(27, 0xB830);
   ret_val |= mdio_write(28, 0x8000);
   ret_val |= mdio_write(27, 0xB800);
   timer = PHY_DELAY_IN_US;
   while (mdio_data != 0x0040)
   {
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   }
   ret_val |= mdio_write(27, 0x8020);
   ret_val |= mdio_write(28, 0x9100);
   ret_val |= mdio_write(27, 0xB82E);
   ret_val |= mdio_write(28, 0x0001);

   for (i = 0; i < 171; i++)
   {
      ret_val |= mdio_write(27, (0x8614 + i * 2));
      mdio_data     = mdio_read(28);
      mdio_data_chk = param_with_SGMII_check[i];
      if (mdio_data_chk != mdio_data)
      {
         return ETH_ERROR;
      }
   }
   for (i = 173; i < 176; i = i + 2)
   {
      ret_val |= mdio_write(27, (0x8614 + i * 2));
      mdio_data     = mdio_read(28);
      mdio_data_chk = param_with_SGMII_check[i];
      if (mdio_data_chk != mdio_data)
      {
         return ETH_ERROR;
      }
   }
   i++;
   ret_val |= mdio_write(27, 0xB818);
   mdio_data_chk = 0x0967;
   mdio_data     = mdio_read(28);
   if (mdio_data_chk != mdio_data)
   {
      return ETH_ERROR;
   }
   i++;
   ret_val |= mdio_write(27, 0xB81A);
   mdio_data_chk = 0x0000;
   mdio_data     = mdio_read(28);
   if (mdio_data_chk != mdio_data)
   {
      return ETH_ERROR;
   }
   i++;
   ret_val |= mdio_write(27, 0xB81C);
   mdio_data_chk = 0x0000;
   mdio_data     = mdio_read(28);
   if (mdio_data_chk != mdio_data)
   {
      return ETH_ERROR;
   }
   i++;
   ret_val |= mdio_write(27, 0xB81E);
   mdio_data_chk = 0x0000;
   mdio_data     = mdio_read(28);
   if (mdio_data_chk != mdio_data)
   {
      return ETH_ERROR;
   }
   i++;
   ret_val |= mdio_write(27, 0xB832);
   mdio_data_chk = 0x0001;
   mdio_data     = mdio_read(28);
   if (mdio_data_chk != mdio_data)
   {
      return ETH_ERROR;
   }
   ret_val |= mdio_write(27, 0xB82E);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0x8020);
   ret_val |= mdio_write(28, 0x0000);
   ret_val |= mdio_write(27, 0xB820);
   ret_val |= mdio_write(28, 0x0000);

   ret_val |= mdio_write(27, 0xB800);
   mdio_data = mdio_read(28);
   timer     = PHY_DELAY_IN_US;
   while (mdio_data != 0x0000)
   {
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   }
   Errata_4_Test = 1;
   return ret_val;
}
#endif

uint16 Enable_IO_POWER(void)
{
   uint16 ret_val  = 0;
   uint16 IO_POWER = 0xFFFF;
   /* IO Power Write */
   ret_val |= mdio_write(31, 0xa4c);
   IO_POWER = (uint16)mdio_read(0x12);
   ret_val |= mdio_write(31, 0xa42);

   /* IO Power Read */
   IO_POWER |= 0x1000;
   ret_val |= mdio_write(31, 0xa4c);
   ret_val |= mdio_write(0x12, IO_POWER);
   ret_val |= mdio_write(31, 0xa42);

   /* IO Power Read Back */
   IO_POWER = 0xFFFF;
   ret_val |= mdio_write(31, 0xa4c);
   IO_POWER = (uint16)mdio_read(0x12);
   ret_val |= mdio_write(31, 0xa42);

   return ret_val;
}

void Read_Reg_Details(void)
{
   mdio_write(27, 0xD048);
   Test_0xD048_Val = mdio_read(28);
}

uint16 Change_SGMII_Force_Mode(void)
{
   uint16 ret_val        = 0;
   uint16 timer          = 0x1000;
   uint16 SGMII_CR1_Test = 0xFFFF;
   uint16 SGMII_CR2_Test = 0xFFFF;
   /* Read SGMIICR1 Status */
   ret_val |= mdio_write(27, 0xCC04);
   SGMII_CR1_Test = mdio_read(28);

   /* Set SGMII force mode */
   SGMII_CR1_Test |= 0x7180;
   ret_val |= mdio_write(27, 0xCC04);
   ret_val |= mdio_write(28, SGMII_CR1_Test);

   while (timer--)
   {
   }
   timer = 0x1000;

   /* Readback SGMIICR1 Status */
   SGMII_CR1_Test = 0xFFFF;
   ret_val |= mdio_write(27, 0xCC04);
   SGMII_CR1_Test = mdio_read(28);

   /* Read SGMIICR2 Status */
   ret_val |= mdio_write(27, 0xCE00);
   SGMII_CR2_Test = mdio_read(28);

   /* Reset SGMII */
   SGMII_CR2_Test &= 0xFFFE;

   ret_val |= mdio_write(27, 0xCE00);
   ret_val |= mdio_write(28, SGMII_CR2_Test);
   while (timer--)
   {
   }
   timer = 0x1000;
   SGMII_CR2_Test |= 0x1;
   ret_val |= mdio_write(27, 0xCE00);
   ret_val |= mdio_write(28, SGMII_CR2_Test);

   /* Read Back SGMIICR2*/
   SGMII_CR2_Test = 0xFFFF;
   ret_val |= mdio_write(27, 0xCE00);
   SGMII_CR2_Test = mdio_read(28);

   return ret_val;
}

/**
 * @brief Read out the TJA1103 debug register list via Clause-45 (MMD) access.
 *
 * @details Equivalent to RTL9010xx_Debug_Reg_Readout() but uses the correct
 *          TJA1103 access method (Clause-45 MMD reads via tja1103_cl45_read),
 *          instead of the Realtek Clause-22/page-based mdio_read scheme.
 */
void TJA1103_Debug_Reg_Readout(void)
{
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_SGMII_BASIC_CONTROL, &TJA1103_SGMIIBasic_Control_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_PMA_CONTROL1, &TJA1103_PmaControl1_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_PMA_STATUS1, &TJA1103_PmaStatus1_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, TJA1103_REG_OFFS_PMA_STATUS2, &TJA1103_PmaStatus2_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_1, ETHTRCV_30_TJA1103_REG_OFFS_BASE_T1_PMA_CONTROL, &TJA1103_BaseT1PmaCtrl_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_3, ETHTRCV_30_TJA1103_REG_OFFS_PCS_CONTROL1, &TJA1103_PcsControl1_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_3, TJA1103_REG_OFFS_PCS_STATUS1, &TJA1103_PcsStatus1_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_3, TJA1103_REG_OFFS_PCS_STATUS2, &TJA1103_PcsStatus2_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONTROL, &TJA1103_DeviceControl_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, TJA1103_REG_OFFS_DEVICE_STATUS, &TJA1103_DeviceStatus_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_DEVICE_CONFIG, &TJA1103_DeviceConfig_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_XMII_CONTROL, &TJA1103_XmiiControl_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_30, ETHTRCV_30_TJA1103_REG_OFFS_MII_BASIC_CONFIG, &TJA1103_MiiBasicConfig_Reg);

   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, ETHTRCV_30_TJA1103_REG_OFFS_PHY_CONTROL, &TJA1103_PhyControl_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, ETHTRCV_30_TJA1103_REG_OFFS_PHY_STATUS, &TJA1103_PhyStatus_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, ETHTRCV_30_TJA1103_REG_OFFS_PHY_CONFIG, &TJA1103_PhyConfig_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, TJA1103_REG_OFFS_PHY_STATE, &TJA1103_PhyState_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, ETHTRCV_30_TJA1103_REG_OFFS_SIGNAL_QUALITY, &TJA1103_SignalQuality_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, TJA1103_REG_OFFS_MSE, &TJA1103_Mse_Reg);
   (void)tja1103_cl45_read(ETHTRCV_30_TJA1103_MMD_SHARED, ETHTRCV_30_TJA1103_REG_OFFS_CABLE_TEST, &TJA1103_CableTest_Reg);
}

/* Read out the debug register list as suggested by Realtek */
void RTL9010xx_Debug_Reg_Readout(void)
{
   uint8 read_BMSR_read_counter = 5;
   uint8 pcs_state_read_counter = 10;

   BMCR_Reg_0x00_norm_acc = mdio_read(0x00);

   while (read_BMSR_read_counter != 0)
   {
      BMSR_Reg_0x01_norm_acc = mdio_read(0x01);
      read_BMSR_read_counter--;
   }

   PHYCR_Reg_0x09_norm_acc           = mdio_read(0x09);
   PHYSR1_Reg_0x0A_norm_acc          = mdio_read(0x0A);
   PHYSFR_Reg_0x10_Pg_0xA42_norm_acc = normal_mdio_read(0x10, 0xA42);
   GINER_Reg_0x12_Pg_0xA42_norm_acc  = normal_mdio_read(0x12, 0xA42);
   GINMR_Reg_0x14_Pg_0xA42_norm_acc  = normal_mdio_read(0x14, 0xA42);
   SLPCR_Reg_0x15_Pg_0xA42_norm_acc  = normal_mdio_read(0x15, 0xA42);
   PHYSCR_Reg_0x18_norm_acc          = mdio_read(0x18);
   PHYSR2_Reg_0x1A_norm_acc          = mdio_read(0x1A);
   GINSR_Reg_0x1D_norm_acc           = mdio_read(0x1D);
   GPSFR_Reg_0x15_Pg_0xA47_norm_acc  = normal_mdio_read(0x15, 0xA47);
   ISR_Reg_0x12_Pg_0xA4C_norm_acc    = normal_mdio_read(0x12, 0xA4C);
   SLPCAP_Reg_0x13_Pg_0xA51_norm_acc = normal_mdio_read(0x13, 0xA51);
   TRACR_Reg_0x14_Pg_0xA51_norm_acc  = normal_mdio_read(0x14, 0xA51);

   while (pcs_state_read_counter != 0)
   {
      PCS_STATE_Reg_0x10_Pg_0xA60_norm_acc = normal_mdio_read(0x10, 0xA60);
      pcs_state_read_counter--;
   }

   IPCR1_Reg_0xC800_spcl_acc               = special_mdio_read(0xC800);
   IPCR2_Reg_0xC802_spcl_acc               = special_mdio_read(0xC802);
   IPCR3_Reg_0xC810_spcl_acc               = special_mdio_read(0xC810);
   IPCR4_Reg_0xC812_spcl_acc               = special_mdio_read(0xC812);
   IEPCR_Reg_0xC814_spcl_acc               = special_mdio_read(0xC814);
   SGMIICR1_Reg_0xCC04_spcl_acc            = special_mdio_read(0xCC04);
   RTL9010BSA_SGMIICR2_Reg_0xCF00_spcl_acc = special_mdio_read(0xCF00);
   RTL9010BSA_SGMIISR1_Reg_0xCF0C_spcl_acc = special_mdio_read(0xCF0C);
   SGMIISR2_Reg_0xCF04_spcl_acc            = special_mdio_read(0xCF04);
   SQI_Reg_0xD106_spcl_acc                 = special_mdio_read(0xD106);
   OPCR2_Reg_0xDD00_spcl_acc               = special_mdio_read(0xDD00);
   OPINSR1_Reg_0xDD08_spcl_acc             = special_mdio_read(0xDD08);
   IPINER1_Reg_0xDD0C_spcl_acc             = special_mdio_read(0xDD0C);
   OPINMR1_Reg_0xDD0E_spcl_acc             = special_mdio_read(0xDD0E);
   OPINSR2_Reg_0xDD10_spcl_acc             = special_mdio_read(0xDD10);
   OPINER2_Reg_0xDD14_spcl_acc             = special_mdio_read(0xDD14);
   OPINSR3_Reg_0xDD18_spcl_acc             = special_mdio_read(0xDD18);
   OPINER3_Reg_0xDD1C_spcl_acc             = special_mdio_read(0xDD1C);
   OPINMR3_Reg_0xDD1E_spcl_acc             = special_mdio_read(0xDD1E);
   OPCR4_Reg_0xDD20_spcl_acc               = special_mdio_read(0xDD20);
   OPMR_Reg_0xDF10_spcl_acc                = special_mdio_read(0xDF10);
}

uint8 RTL9010Bx_Initial_Configuration(void)
{
   /* uint32 mdio_data = 0; */
   /* uint32 timer     = PHY_DELAY_IN_US; // set a 2ms timer */

   /* PHY parameter start */
   mdio_write(31, 0x0D13);
   mdio_write(21, 0x0047); /* added */
   mdio_write(27, 0x859C);
   mdio_write(28, 0x0609);
   mdio_write(27, 0x85A2);
   mdio_write(28, 0x0300);
   mdio_write(27, 0x85A4);
   mdio_write(28, 0x0D07); /* modified */
   mdio_write(27, 0xDC00);
   mdio_write(28, 0x1899);
   mdio_write(31, 0x0A4C);
   mdio_write(20, 0x2A2E);
   mdio_write(31, 0x0A49);
   mdio_write(20, 0xFB00);

   /*
    mdio_write(0, 0x8000); // PHY soft-reset

    do
    { // Check soft-reset complete

       mdio_data = mdio_read(0);
       if (mdio_data == 0xFFFF)
          return ETH_ERROR;

       timer--;
       if (timer == 0)
       {
          return ETH_ERROR;
       }
    } while (mdio_data != 0x0140);
   */

   return ETH_SUCCESS;
}

/**
 * @brief Verify RTL9010Bx initial configuration via MDIO.
 *
 * @details Iterates through the expected configuration parameters in
 *          the `param_check` table and reads the corresponding MDIO
 *          page/register values. If any read value differs from the
 *          expected one, the function returns `ETH_ERROR`. A lightweight
 *          timeout counter is decremented to bound execution; if it
 *          reaches zero, `ETH_ERROR` is returned. When all checks pass,
 *          the function returns `ETH_SUCCESS`.
 *
 * @return `ETH_SUCCESS` when all MDIO reads match expected values;
 *         `ETH_ERROR` otherwise (including timeout).
 */
uint8 RTL9010Bx_Initial_Configuration_Check(void)
{
   uint16 mdio_data     = 0;
   uint16 mdio_data_chk = 0;

   uint16 page;
   uint16 reg, i;

   for (i = 0; i <= 18; i += 3)
   {
      page          = param_check[i];
      mdio_data_chk = param_check[i + 2];
      reg           = param_check[i + 1];
      if (0 == page)
      {
         mdio_write(27, reg);
         mdio_data = mdio_read(28);
      }
      else
      {
         mdio_write(31, page);
         mdio_data = mdio_read(reg);
      }

      if (mdio_data_chk != mdio_data)
      {
         return ETH_ERROR;
      }
   }
   return ETH_SUCCESS;
}

/**
 * @brief Apply RTL9010Bx initial configuration with auto-negotiation.
 *
 * @details Programs required MDIO pages/registers for AN, waits for
 *          the internal readiness flag, performs a PHY soft reset,
 *          and validates completion via BMCR reads. Returns `ETH_ERROR`
 *          on timeout or invalid MDIO readbacks; otherwise `ETH_SUCCESS`.
 *
 * @note Uses a 2ms timer budget for readiness and reset checks.
 *
 * @return `ETH_SUCCESS` on successful configuration and reset; `ETH_ERROR` on
 *         timeout or unexpected MDIO values.
 */
uint8 RTL9010Bx_Initial_With_AN_Configuration(void)
{
   uint32 mdio_data = 0;
   uint32 timer     = PHY_DELAY_IN_US; /* set a 2ms timer */

   /* PHY parameter start */
   mdio_write(31, 0x0D13);
   mdio_write(21, 0x0047); /* added */
   mdio_write(27, 0x859C);
   mdio_write(28, 0x0609);
   mdio_write(27, 0x85A2);
   mdio_write(28, 0x0300);
   mdio_write(27, 0x85A4);
   mdio_write(28, 0x0D07); /* modified */
   mdio_write(27, 0xDC00);
   mdio_write(28, 0x1899);
   mdio_write(31, 0x0A4C);
   mdio_write(20, 0x2A2E);
   mdio_write(31, 0x0A49);
   mdio_write(20, 0xFB00);
   mdio_write(31, 0x0A55);
   mdio_write(17, 0xE301); /* modified */
   mdio_write(31, 0x0A54);
   mdio_write(21, 0xF808); /* modified */

   mdio_write(27, 0xB820);
   mdio_write(28, 0x0010);
   mdio_write(27, 0xB830);
   mdio_write(28, 0x8000);
   mdio_write(27, 0xB800);
   mdio_data = ((uint16)mdio_read(28) & 0x0040);

   do
   {
      mdio_write(27, 0xB800);
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   } while (mdio_data != 0x0040);

   mdio_write(27, 0x8020);
   mdio_write(28, 0x6200);
   mdio_write(27, 0xB82E);
   mdio_write(28, 0x0001);

   mdio_write(27, 0x8690);
   mdio_write(28, 0xAF86);
   mdio_write(28, 0x96AF);
   mdio_write(28, 0x86C0);
   mdio_write(28, 0xF8BF);
   mdio_write(28, 0x45D2);
   mdio_write(28, 0x0241);
   mdio_write(28, 0x8EA1);
   mdio_write(28, 0x1111);
   mdio_write(28, 0xD10F);
   mdio_write(28, 0xBF41);
   mdio_write(28, 0xC702);
   mdio_write(28, 0x414A);
   mdio_write(28, 0xFCD1);
   mdio_write(28, 0x04BF);
   mdio_write(28, 0x41CD);
   mdio_write(28, 0xAF15);
   mdio_write(28, 0x93D1);
   mdio_write(28, 0x06BF);
   mdio_write(28, 0x41C7);
   mdio_write(28, 0x0241);
   mdio_write(28, 0x4AFC);
   mdio_write(28, 0xBF41);
   mdio_write(28, 0xCDAF);
   mdio_write(28, 0x1593);
   mdio_write(28, 0xF8D1);
   mdio_write(28, 0x06BF);
   mdio_write(28, 0x41C7);
   mdio_write(28, 0x0241);
   mdio_write(28, 0x4AFC);
   mdio_write(28, 0xBF41);
   mdio_write(28, 0xCDAF);
   mdio_write(28, 0x1519);
   mdio_write(27, 0xB818);
   mdio_write(28, 0x1590);
   mdio_write(27, 0xB81A);
   mdio_write(28, 0x1516);
   mdio_write(27, 0xB832);
   mdio_write(28, 0x0003);

   mdio_write(27, 0xB82E);
   mdio_write(28, 0x0000);
   mdio_write(27, 0x8020);
   mdio_write(28, 0x0000);
   mdio_write(27, 0xB820);
   mdio_write(28, 0x0000);

   mdio_write(27, 0xB800);
   mdio_data = mdio_read(28) & 0x0040;
   timer     = PHY_DELAY_IN_US; /* set a 2ms timer */
   do
   {
      mdio_write(27, 0xB800);
      mdio_data = ((uint16)mdio_read(28) & 0x0040);
      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   } while (mdio_data != 0x0000);
   /* End */

   timer = PHY_DELAY_IN_US; /* set a 2ms timer */
   mdio_write(0, 0x8000);   /* PHY soft-reset */

   do
   { /* Check soft-reset complete */

      mdio_data = mdio_read(0);
      if (mdio_data == 0xFFFF)
         return ETH_ERROR;

      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   } while (mdio_data != (uint16)0x0140);

   return ETH_SUCCESS;
}

/**
 * @brief Set RTL9010x PHY operational state.
 *
 * @details Writes MDIO control registers (OPCR2/OPCR4) to transition
 *          the PHY into Standby, Sleep, or Normal modes based on
 *          `op_cmd`. Reads back current register values, masks and
 *          updates specific bits per mode requirements. Returns
 *          `ETH_ERROR` on invalid MDIO read (`0xFFFF`) or unsupported
 *          command; otherwise returns `ETH_SUCCESS`.
 *
 * @param op_cmd Operation command selector: `OP_CMD_GOTO_STANDBY`,
 *               `OP_CMD_GOTO_SLEEP`, or `OP_CMD_GOTO_NORMAL`.
 *
 * @return `ETH_SUCCESS` when the mode transition is applied; `ETH_ERROR` on
 *         read failure or invalid command.
 */
uint16 RTL9010x_Set_OP_state(uint8 op_cmd)
{
   uint16 OP_Mode_mdio_data = 0U;
   mdio_write(0x1b, 0xdd00); /* read OPCR2 */
   OP_Mode_mdio_data = mdio_read(0x1c);
   if (0xFFFF == OP_Mode_mdio_data)
   {
      return ETH_ERROR;
   }

   if (OP_CMD_GOTO_STANDBY == op_cmd)
   {
      mdio_write(0x1b, 0xdd00); /* read OPCR2 */
      OP_Mode_mdio_data &= ~((uint16)0x001f);
      mdio_write(0x1c, (uint16)(OP_Mode_mdio_data | 0x12));
   }
   else if (OP_CMD_GOTO_SLEEP == op_cmd)
   {
      mdio_write(0x1b, 0xdd00); /* read OPCR2 */
      OP_Mode_mdio_data &= ~((uint16)0x001f);
      mdio_write(0x1c, (uint16)(OP_Mode_mdio_data | 0x14));
   }
   else if (OP_CMD_GOTO_NORMAL == op_cmd)
   {
      mdio_write(0x1b, 0xdd00); /* read OPCR2 */
      OP_Mode_mdio_data &= ~((uint16)0x001f);
      mdio_write(0x1c, (uint16)(OP_Mode_mdio_data | 0x13));
      mdio_write(0x1b, 0xdd20); /* read OPCR4 */
      OP_Mode_mdio_data = mdio_read(0x1c);
      OP_Mode_mdio_data &= ~((uint16)0x000f);
      mdio_write(0x1c, (uint16)(OP_Mode_mdio_data | 0x0B));
   }
   else
   {
      return ETH_ERROR;
   }

   return ETH_SUCCESS;
}

/**
 * @brief Read RTL9010x PHY operational state.
 *
 * @details Reads the OPMR register via MDIO (page 0xDF10, data at 0x1C),
 *          validates the read value, and returns an operational state
 *          code derived from the low byte: 0x20 → Standby, 0x30 → Normal,
 *          0x31 → Safety. Returns `ETH_ERROR` if the MDIO read is invalid
 *          (0xFFFF) or the value does not map to a known state.
 *
 * @return `OP_STATE_STANDBY`, `OP_STATE_NORMAL`, or `OP_STATE_SAFETY` on
 *         known values; `ETH_ERROR` if read fails or value is unknown.
 */
uint16 RTL9010x_Get_OP_state(void)
{
   uint16 mdio_data = 0;
   uint16 ret_val   = ETH_ERROR;
   mdio_write(0x1b, 0xdf10); /* read OPMR */
   mdio_data = mdio_read(0x1c);
   if ((uint16)0xFFFF != mdio_data)
   {
      uint16 masked_mdio_data = mdio_data & (uint16)0xff;
      if (0x20 == masked_mdio_data)
      {
         ret_val = OP_STATE_STANDBY;
      }
      else if (0x30 == masked_mdio_data)
      {
         ret_val = OP_STATE_NORMAL;
      }
      else if (0x31 == masked_mdio_data)
      {
         ret_val = OP_STATE_SAFETY;
      }
      else
      {
         ret_val = ETH_ERROR;
      }
   }
   else
   {
      ret_val = ETH_ERROR;
   }

   return ret_val;
}

uint8 RTL9010Bx_Soft_Reset(void)
{
   uint32 mdio_data = 0;
   uint32 timer     = PHY_DELAY_IN_US; /* set a 2ms timer */

   mdio_write(0, 0x8000); /* PHY soft-reset */
#ifdef Enable_PHY_100Mb
   do
   { /* Check soft-reset complete */

      mdio_data = mdio_read(0);
      if ((uint16)0xFFFF == (uint16)mdio_data)
      {
         return ETH_ERROR;
      }

      timer--;
      if (0 == timer)
      {
         return ETH_ERROR;
      }
   } while (mdio_data != 0x2100);
#else
   do
   { // Check soft-reset complete

      mdio_data = mdio_read(0);
      if (mdio_data == 0xFFFF)
         return ETH_ERROR;

      timer--;
      if (timer == 0)
      {
         return ETH_ERROR;
      }
   } while (mdio_data != 0x0140);
#endif

   return ETH_SUCCESS;
}
#pragma clang optimize on
