#ifndef PHY_USER_CBK_H
#define PHY_USER_CBK_H
/*===========================================================================*\
 * FILE: PHY_User_Cbk.h
 *===========================================================================
 * Copyright (C) 2026 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   Declares PHY (Physical Layer) user callback interfaces and MDIO helper APIs
 *   for the RTL9010 Ethernet transceiver. Includes initialization hooks,
 *   operational state control, and link configuration functions used by the
 *   AUTOSAR Ethernet Transceiver stack.
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
#include "EthIf_GenTypes.h" /* EthIf_ConfigType, EthIf_PCConfig extern, EthIf_Config_RDR_xx macros */
#include "EthTrcv_30_Rtl9010.h"
#include "EthTrcv_30_Rtl9010_HwAccess_Ifc_Int.h"
#include "EthTrcv_30_Rtl9010_LL_Regs.h"
#include "EthTrcv_30_Tja1103.h"
#include "EthTrcv_30_Tja1103_HwAccess_Ifc_Int.h"
#include "EthTrcv_30_Tja1103_LL_Regs.h"
/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/
#define ETH_SUCCESS (uint8)0
#define ETH_ERROR   (uint8)1

#define ENABLE_NWAY_CONFIGURATION (0U)
#define OP_STATE_STANDBY          0x1A
#define OP_STATE_NORMAL           0x1B
#define OP_STATE_SAFETY           0x1C

#define OP_CMD_GOTO_STANDBY (uint8)0x11
#define OP_CMD_GOTO_SLEEP   (uint8)0x12
#define OP_CMD_GOTO_NORMAL  (uint8)0x13

/* PHY Manufacturer Identification via IEEE 802.3 PHY ID Register 2 (Clause 22 reg 2) */
/* Values confirmed from EthTrcv_30_Rtl9010_LL_Regs.h and EthTrcv_30_Tja1103_LL_Regs.h */
#define PHY_ID1_REALTEK_RTL_xx (0x001Cu) /* OUI bits[3:18], OUI = 00:E0:4C (Realtek) */
#define PHY_ID1_NXP_TJA_xx     (0x001Bu) /* OUI bits[3:18], OUI = 00:60:37 (NXP)     */
#define PHY_ID2_NXP_TJA1103    (0xB013u) /* TJA1103 sub-model value 0xB013 */
#define PHY_ID2_NXP_TJA1120    (0xB031u) /* TJA1120 sub-model value 0xB030 */

/* PHY Manufacturer identifiers stored in detected_phy_manufacturer */
typedef enum
{
   PHY_MFR_UNKNOWN = 0u,
   PHY_MFR_REALTEK = 1u,
   PHY_MFR_NXP     = 2u
} PHY_Manufacturer_t;

/* RTL PHY sub-model BMCR default after soft reset (confirmed from EthTrcv_30_Rtl9010_Lcfg.c index 1) */
#define RTL9000CRG_BMCR_NORMAL_MODE (0x2100u) /* RTL9000CSA: 100Mb, Full Duplex, AN disabled */

/*===========================================================================*
 * Exported Type Definitions
 *===========================================================================*/
/** PHY sub-model identifier, determined at runtime by Determine_PHY_Manufacturer() / Determine_RTL_PHY_Model() */
typedef enum RTL_PHY_MODEL_Tag
{
   RTL_9010x   = 0, /* RTL9010BSA — 1000BASE-T1, 1 Gbps   */
   RTL_9000Cx  = 1, /* RTL9000CSA — 100BASE-T1, 100 Mbps */
   NXP_TJA1103 = 2, /* NXP TJA1103 — 100BASE-T1, 100 Mbps  */
   NXP_TJA1120 = 3, /* NXP TJA1120 — 1000BASE-T1, 1 Gbps   */
   NXP_RTL_PHY_NUM  /* sentinel / unknown                   */
} NXP_RTL_PHY_MODEL_T;

/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
/* RTL9010 / RTL9000 callbacks */
void RTL_PHY_Pre_Init(uint8 TrcvIdx);
void RTL_PHY_Post_Init(uint8 TrcvIdx);

/* TJA1103 callbacks */
void TJA1103_PHY_Pre_Init(uint8 TrcvIdx);
void TJA1103_PHY_Post_Init(uint8 TrcvIdx);
extern volatile PHY_Manufacturer_t detected_phy_manufacturer;
/* RTL Clause-22 Register Access APIs */
uint16 mdio_write(uint8 RegAddr, uint16 RegVal);
uint16 mdio_read(uint8 RegAddr);
void normal_mdio_write(uint16 RegAddr, uint16 RegPage, uint16 RegVal);
uint16 normal_mdio_read(uint16 RegAddr, uint16 RegPage);
uint16 special_mdio_read(uint16 RegAddr);
uint16 special_mdio_write(uint16 RegAddr, uint16 RegVal);
/* TJA1103 Clause-45 (MMD) Register Access APIs */
Std_ReturnType tja1103_cl45_write(uint8 DevAddr, uint16 RegAddr, uint16 RegVal);
Std_ReturnType tja1103_cl45_read(uint8 DevAddr, uint16 RegAddr, uint16 *RegValPtr);
Std_ReturnType tja1103_cl22_read(uint8 RegAddr, uint16 *RegValPtr);

uint16 Enable_IO_POWER(void);
uint16 Change_SGMII_Force_Mode(void);

#if ENABLE_NWAY_CONFIGURATION
uint16 RTL9010Ax_Initial_with_SGMII_Configuration(void);
uint16 RTL9010Ax_Initial_with_NWAY_Configuration_Check(void);
uint16 RTL9010Ax_Initial_with_NWAY_Configuration(void);
uint16 RTL9010Ax_Initial_with_SGMII_Configuration_Check(void);
#endif
extern volatile NXP_RTL_PHY_MODEL_T lMcal_Init_Phy_Model;
uint16 RTL9010x_Get_OP_state(void);
uint16 RTL9010x_Set_OP_state(uint8 op_cmd);

uint8 RTL9010Bx_Initial_Configuration(void);
uint8 RTL9010Bx_Initial_Configuration_Check(void);
uint8 RTL9010Bx_Initial_With_AN_Configuration(void);
uint8 RTL9010Bx_Initial_With_AN_Configuration_Check(void);
uint8 RTL9010Bx_Soft_Reset(void);
uint8 RTL9010Bx_9000Cx_Soft_Reset(void);           /* soft reset for both RTL9010Bx and RTL9000Cx */
NXP_RTL_PHY_MODEL_T Determine_RTL_PHY_Model(void); /* runtime PHY sub-model detection via BMCR readback */
NXP_RTL_PHY_MODEL_T Detect_PHY_Model(void);        /* PHY manufacturer/sub-model detection via PHY_ID1   */
NXP_RTL_PHY_MODEL_T Get_PHY_Model(void);           /* Return the PHY Model that has been detected previously */

void RTL9010xx_Debug_Reg_Readout(void);
void TJA1103_Debug_Reg_Readout(void); /* TJA1103 equivalent, uses Clause-45 MMD access */
void PHY_Cyclic_BMCR_Monitor(void);   /* cyclic BMCR readback — call every 50 ms */
void TJA11xx_Errata_Handling(void);
void TJA1120_Init_Sequence(void);
void TJA1103_Init_Sequence(void);
extern void disable_ethernet_clocks(void);
/*===========================================================================*
 * Exported Type Declarations
 *===========================================================================*/
/* Debug Variables for 9010AS*/
extern volatile uint16 BMCR_Reg_0x00_norm_acc;
extern volatile uint16 BMSR_Reg_0x01_norm_acc;
extern volatile uint16 PHYCR_Reg_0x09_norm_acc;
extern volatile uint16 PHYSR1_Reg_0x0A_norm_acc;
extern volatile uint16 PHYSFR_Reg_0x10_Pg_0xA42_norm_acc;
extern volatile uint16 GINER_Reg_0x12_Pg_0xA42_norm_acc;
extern volatile uint16 GINMR_Reg_0x14_Pg_0xA42_norm_acc;
extern volatile uint16 SLPCR_Reg_0x15_Pg_0xA42_norm_acc;
extern volatile uint16 PHYSCR_Reg_0x18_norm_acc;
extern volatile uint16 PHYSR2_Reg_0x1A_norm_acc;
extern volatile uint16 GINSR_Reg_0x1D_norm_acc;
extern volatile uint16 GPSFR_Reg_0x15_Pg_0xA47_norm_acc;
extern volatile uint16 ISR_Reg_0x12_Pg_0xA4C_norm_acc;
extern volatile uint16 SLPCAP_Reg_0x13_Pg_0xA51_norm_acc;
extern volatile uint16 TRACR_Reg_0x14_Pg_0xA51_norm_acc;
extern volatile uint16 PCS_STATE_Reg_0x10_Pg_0xA60_norm_acc;
extern volatile uint16 IPCR1_Reg_0xC800_spcl_acc;
extern volatile uint16 IPCR2_Reg_0xC802_spcl_acc;
extern volatile uint16 IPCR3_Reg_0xC810_spcl_acc;
extern volatile uint16 IPCR4_Reg_0xC812_spcl_acc;
extern volatile uint16 IEPCR_Reg_0xC814_spcl_acc;
extern volatile uint16 SGMIICR1_Reg_0xCC04_spcl_acc;
extern volatile uint16 SGMIICR2_Reg_0xCE00_spcl_acc;
extern volatile uint16 SGMIISR1_Reg_0xCE0C_spcl_acc;
extern volatile uint16 SGMIISR2_Reg_0xCF04_spcl_acc;
extern volatile uint16 SQI_Reg_0xD106_spcl_acc;
extern volatile uint16 OPCR2_Reg_0xDD00_spcl_acc;
extern volatile uint16 OPINSR1_Reg_0xDD08_spcl_acc;
extern volatile uint16 IPINER1_Reg_0xDD0C_spcl_acc;
extern volatile uint16 OPINMR1_Reg_0xDD0E_spcl_acc;
extern volatile uint16 OPINSR2_Reg_0xDD10_spcl_acc;
extern volatile uint16 OPINER2_Reg_0xDD14_spcl_acc;
extern volatile uint16 OPINSR3_Reg_0xDD18_spcl_acc;
extern volatile uint16 OPINER3_Reg_0xDD1C_spcl_acc;
extern volatile uint16 OPINMR3_Reg_0xDD1E_spcl_acc;
extern volatile uint16 OPCR4_Reg_0xDD20_spcl_acc;
extern volatile uint16 OPMR_Reg_0xDF10_spcl_acc;
/* debug vars for 9010BSA */
extern volatile uint16 RTL9010BSA_SGMIICR2_Reg_0xCF00_spcl_acc;
extern volatile uint16 RTL9010BSA_SGMIISR1_Reg_0xCF0C_spcl_acc;
/* PHY sub-model detection debug vars */
extern volatile uint16 StandBy_BMCR_Default;
extern volatile uint16 NormalMode_BMCR_Default;
extern volatile uint16_t PHY_BMCR_Reg; /* BMCR snapshot read during PHY detection     */

/* 100BASE-T1 Post_Init diagnostic variables */
extern volatile uint16 IPCR1_before_write; /* IPCR1 hardware default before our write      */
extern volatile uint16 IPCR2_d_post_init;  /* 0xC802: T1 extended ctrl / partner detection */
extern volatile uint16 IPCR3_d_post_init;  /* 0xC810: T1 pair status                       */
/* Runtime-selected EthIf configuration pointer — set in Determine_RTL_PHY_Model() based on detected PHY.
 * EthIf_Config_RDR_01_Ptr => RTL9010BSA (combo PHY), EthIf_Config_RDR_02_Ptr => RTL9000CSA (100Mb non-combo) */
/* TJA1103 debug variables */
extern uint16 TJA1103_PhyControl_Reg;     /* MMD_SHARED, 0x8100: PHY_CONTROL                    */
extern uint16 TJA1103_PhyStatus_Reg;      /* MMD_SHARED, 0x8102: PHY_STATUS (link/SQI)          */
extern uint16 TJA1103_DeviceControl_Reg;  /* MMD_30,     0x0040: DEVICE_CONTROL                 */
extern uint16 TJA1103_XmiiControl_Reg;    /* MMD_30,     0xAFC0: XMII_CONTROL                   */
extern uint16 TJA1103_MiiBasicConfig_Reg; /* MMD_30,     0xAFC6: MII_BASIC_CONFIG               */
extern uint16 TJA1103_BaseT1PmaCtrl_Reg;  /* MMD_1,      0x0834: BASE_T1_PMA_CONTROL (M/S)      */
extern uint16 TJA1103_SignalQuality_Reg;  /* MMD_SHARED, 0x8320: SIGNAL_QUALITY (SQI)           */
/* TJA1103_Debug_Reg_Readout() debug variables */
extern uint16 TJA1103_PmaControl1_Reg;  /* MMD_1,      0x0000: PMA_CONTROL1                   */
extern uint16 TJA1103_PmaStatus1_Reg;   /* MMD_1,      0x0001: PMA_STATUS1                    */
extern uint16 TJA1103_PmaStatus2_Reg;   /* MMD_1,      0x0008: PMA_STATUS2                    */
extern uint16 TJA1103_PcsControl1_Reg;  /* MMD_3,      0x0000: PCS_CONTROL1                   */
extern uint16 TJA1103_PcsStatus1_Reg;   /* MMD_3,      0x0001: PCS_STATUS1                    */
extern uint16 TJA1103_PcsStatus2_Reg;   /* MMD_3,      0x0008: PCS_STATUS2                    */
extern uint16 TJA1103_DeviceConfig_Reg; /* MMD_30,     0x0048: DEVICE_CONFIG                  */
extern uint16 TJA1103_DeviceStatus_Reg; /* MMD_30,     0x0042: DEVICE_STATUS                  */
extern uint16 TJA1103_PhyConfig_Reg;    /* MMD_SHARED, 0x8108: PHY_CONFIG                     */
extern uint16 TJA1103_PhyState_Reg;     /* MMD_SHARED, 0x810C: PHY_STATE                      */
extern uint16 TJA1103_Mse_Reg;          /* MMD_SHARED, 0x8324: MSE                            */
extern uint16 TJA1103_CableTest_Reg;    /* MMD_SHARED, 0x8330: CABLE_TEST                     */
#endif
