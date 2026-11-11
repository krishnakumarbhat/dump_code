#ifndef SWC_PLT_CDD_FCRU_H
#define SWC_PLT_CDD_FCRU_H
/*===========================================================================*\
 * FILE: SWC_PLT_CDD_FCRU.h
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

/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/
/* MACROs to Change the PMU_FAULTB  */
#define ACTIVE_LOW_INACTIVE_HIGH ((uint32)0x00000002U)
#define ACTIVE_HIGH_INACTIVE_LOW ((uint32)0x00000010U)

/* MACROs for Fault Status */
#define PIN_EN_STATUS     (0x1U)
#define RST_EN_STATUS     (0x2U)
#define PIN_RST_EN_STATUS (0x3U)

#if (TRUE == XCP_FAULT_INJECTION)
   /* Macros for Fault Injection */
   #define IC_INJECT_FAULT    (0x00U)
   #define IC_REMOVE_FAULT    (0x01U)
   #define MAX_FCRU_FAULT_NUM (63U)
#endif

#if (STD_ON == ENABLE_SIT_TEST_STUBS)
void FCRU_Integration_Test(void);
#endif

#if (STD_ON == ENABLE_SQT_TEST_STUBS)
void FCRU_Functionality_Test(void);
#endif

#ifndef UNIT_TEST
   /* MACROs for register address */
   #define FCRU_CTRL_00_ADDR (((*(volatile uint32_t *)0x89004050))) /* FAULT_PIN_ENA Config for Fault0 to Fault31 */
   #define FCRU_CTRL_01_ADDR (((*(volatile uint32_t *)0x89004054))) /* FAULT_PIN_ENA Config for Fault32 to Fault63 */
   #define FCRU_CTRL_02_ADDR (((*(volatile uint32_t *)0x89004058))) /* FAULT_RST_ENA Config for Fault0 to Fault31 */
   #define FCRU_CTRL_03_ADDR (((*(volatile uint32_t *)0x8900405C))) /* FAULT_RST_ENA Config for Fault32 to Fault63 */
   #define FCRU_CTRL_08_ADDR (((*(volatile uint32_t *)0x89004070))) /* FAULT_CAP_BYP Config for Fault0 to Fault31 */
   #define FCRU_CTRL_09_ADDR (((*(volatile uint32_t *)0x89004074))) /* FAULT_CAP_BYP Config for Fault32 to Fault63 */
   #define FCRU_CTRL_10_ADDR (((*(volatile uint32_t *)0x89004078))) /* PIN_ACTIVE_STATE_CTRL & PIN_INACTIVE_STATE_CTRL Config */

   #define FCRU_CTRL_04_ADDR (((*(volatile uint32_t *)0x89004060))) /* FAULT_PIN_ENA Config for Fault0 to Fault31 */
   #define FCRU_CTRL_05_ADDR (((*(volatile uint32_t *)0x89004064))) /* FAULT_PIN_ENA Config for Fault32 to Fault63 */
   #define FCRU_CTRL_06_ADDR (((*(volatile uint32_t *)0x89004068))) /* FAULT_RST_ENA Config for Fault0 to Fault31 */
   #define FCRU_CTRL_07_ADDR (((*(volatile uint32_t *)0x8900406C))) /* FAULT_RST_ENA Config for Fault32 to Fault63 */

   #define FCRU_DIAG_00_ADDR (((*(volatile uint32_t *)0x89004088))) /* PIN_ACTIVE_STATE_CTRL & PIN_INACTIVE_STATE_CTRL Config */
   #define FCRU_DIAG_01_ADDR (((*(volatile uint32_t *)0x8900408C))) /* PIN_ACTIVE_STATE_CTRL & PIN_INACTIVE_STATE_CTRL Config */
   #define FCRU_DIAG_02_ADDR (((*(volatile uint32_t *)0x89004090))) /* PIN_ACTIVE_STATE_CTRL & PIN_INACTIVE_STATE_CTRL Config */
   #define FCRU_DIAG_03_ADDR (((*(volatile uint32_t *)0x89004094))) /* PIN_ACTIVE_STATE_CTRL & PIN_INACTIVE_STATE_CTRL Config */

   #define FCRU_CTRL_11_ADDR (((*(volatile uint32_t *)0x8900407C))) /* FORCE_FAULT0 config for fault0 to fault 31 */
   #define FCRU_CTRL_12_ADDR (((*(volatile uint32_t *)0x89004080))) /* FORCE_FAULT1 config for fault32 to fault 63 */
   #define FCRU_KEY_ADDR     (((*(volatile uint32_t *)0x89004084))) /* Key Register Address */
#endif

#define FCRU_KEY_SET   ((uint32)0xCAB005E5U) /* Valid Key Value  */
#define FCRU_KEY_CLEAR ((uint32)0x00000000U) /* Invalid Key Value  */

/* Reset Enable Configuration Macros */
#define ENABLE_BIT   ((uint32)0x00000001U)
#define DISABLE_BIT  ((uint32)0x00000000U)
#define SET_ALL_BITS ((uint32)0xFFFFFFFFU)
/* MACRO to Set(ENABLE) FCRU Fault Bits */
#define ENABLE_FCRU_FAULT_00 ((uint32)0x00000001U)
#define ENABLE_FCRU_FAULT_01 ((uint32)0x00000002U)
#define ENABLE_FCRU_FAULT_02 ((uint32)0x00000004U)
#define ENABLE_FCRU_FAULT_03 ((uint32)0x00000008U)
#define ENABLE_FCRU_FAULT_04 ((uint32)0x00000010U)
#define ENABLE_FCRU_FAULT_05 ((uint32)0x00000020U)
#define ENABLE_FCRU_FAULT_06 ((uint32)0x00000040U)
#define ENABLE_FCRU_FAULT_07 ((uint32)0x00000080U)
#define ENABLE_FCRU_FAULT_08 ((uint32)0x00000100U)
#define ENABLE_FCRU_FAULT_09 ((uint32)0x00000200U)
#define ENABLE_FCRU_FAULT_10 ((uint32)0x00000400U)
#define ENABLE_FCRU_FAULT_11 ((uint32)0x00000800U)
#define ENABLE_FCRU_FAULT_12 ((uint32)0x00001000U)
#define ENABLE_FCRU_FAULT_13 ((uint32)0x00002000U)
#define ENABLE_FCRU_FAULT_14 ((uint32)0x00004000U)
#define ENABLE_FCRU_FAULT_15 ((uint32)0x00008000U)
#define ENABLE_FCRU_FAULT_16 ((uint32)0x00010000U)
#define ENABLE_FCRU_FAULT_17 ((uint32)0x00020000U)
#define ENABLE_FCRU_FAULT_18 ((uint32)0x00040000U)
#define ENABLE_FCRU_FAULT_19 ((uint32)0x00080000U)
#define ENABLE_FCRU_FAULT_20 ((uint32)0x00100000U)
#define ENABLE_FCRU_FAULT_21 ((uint32)0x00200000U)
#define ENABLE_FCRU_FAULT_22 ((uint32)0x00400000U)
#define ENABLE_FCRU_FAULT_23 ((uint32)0x00800000U)
#define ENABLE_FCRU_FAULT_24 ((uint32)0x01000000U)
#define ENABLE_FCRU_FAULT_25 ((uint32)0x02000000U)
#define ENABLE_FCRU_FAULT_26 ((uint32)0x04000000U)
#define ENABLE_FCRU_FAULT_27 ((uint32)0x08000000U)
#define ENABLE_FCRU_FAULT_28 ((uint32)0x10000000U)
#define ENABLE_FCRU_FAULT_29 ((uint32)0x20000000U)
#define ENABLE_FCRU_FAULT_30 ((uint32)0x40000000U)
#define ENABLE_FCRU_FAULT_31 ((uint32)0x80000000U)
#define ENABLE_FCRU_FAULT_32 ((uint32)0x00000001U)
#define ENABLE_FCRU_FAULT_33 ((uint32)0x00000002U)
#define ENABLE_FCRU_FAULT_34 ((uint32)0x00000004U)
#define ENABLE_FCRU_FAULT_35 ((uint32)0x00000008U)
#define ENABLE_FCRU_FAULT_36 ((uint32)0x00000010U)
#define ENABLE_FCRU_FAULT_37 ((uint32)0x00000020U)
#define ENABLE_FCRU_FAULT_38 ((uint32)0x00000040U)
#define ENABLE_FCRU_FAULT_39 ((uint32)0x00000080U)
#define ENABLE_FCRU_FAULT_40 ((uint32)0x00000100U)
#define ENABLE_FCRU_FAULT_41 ((uint32)0x00000200U)
#define ENABLE_FCRU_FAULT_42 ((uint32)0x00000400U)
#define ENABLE_FCRU_FAULT_43 ((uint32)0x00000800U)
#define ENABLE_FCRU_FAULT_44 ((uint32)0x00001000U)
#define ENABLE_FCRU_FAULT_45 ((uint32)0x00002000U)
#define ENABLE_FCRU_FAULT_46 ((uint32)0x00004000U)
#define ENABLE_FCRU_FAULT_47 ((uint32)0x00008000U)
#define ENABLE_FCRU_FAULT_48 ((uint32)0x00010000U)
#define ENABLE_FCRU_FAULT_49 ((uint32)0x00020000U)
#define ENABLE_FCRU_FAULT_50 ((uint32)0x00040000U)
#define ENABLE_FCRU_FAULT_51 ((uint32)0x00080000U)
#define ENABLE_FCRU_FAULT_52 ((uint32)0x00100000U)
#define ENABLE_FCRU_FAULT_53 ((uint32)0x00200000U)
#define ENABLE_FCRU_FAULT_54 ((uint32)0x00400000U)
#define ENABLE_FCRU_FAULT_55 ((uint32)0x00800000U)
#define ENABLE_FCRU_FAULT_56 ((uint32)0x01000000U)
#define ENABLE_FCRU_FAULT_57 ((uint32)0x02000000U)
#define ENABLE_FCRU_FAULT_58 ((uint32)0x04000000U)
#define ENABLE_FCRU_FAULT_59 ((uint32)0x08000000U)
#define ENABLE_FCRU_FAULT_60 ((uint32)0x10000000U)
#define ENABLE_FCRU_FAULT_61 ((uint32)0x20000000U)
#define ENABLE_FCRU_FAULT_62 ((uint32)0x40000000U)
#define ENABLE_FCRU_FAULT_63 ((uint32)0x80000000U)

/* MACRO to Keep FCRU Fault Bits DISBALE */
#define DISABLE_FCRU_FAULT_00 DISABLE_BIT
#define DISABLE_FCRU_FAULT_01 DISABLE_BIT
#define DISABLE_FCRU_FAULT_02 DISABLE_BIT
#define DISABLE_FCRU_FAULT_03 DISABLE_BIT
#define DISABLE_FCRU_FAULT_04 DISABLE_BIT
#define DISABLE_FCRU_FAULT_05 DISABLE_BIT
#define DISABLE_FCRU_FAULT_06 DISABLE_BIT
#define DISABLE_FCRU_FAULT_07 DISABLE_BIT
#define DISABLE_FCRU_FAULT_08 DISABLE_BIT
#define DISABLE_FCRU_FAULT_09 DISABLE_BIT
#define DISABLE_FCRU_FAULT_10 DISABLE_BIT
#define DISABLE_FCRU_FAULT_11 DISABLE_BIT
#define DISABLE_FCRU_FAULT_12 DISABLE_BIT
#define DISABLE_FCRU_FAULT_13 DISABLE_BIT
#define DISABLE_FCRU_FAULT_14 DISABLE_BIT
#define DISABLE_FCRU_FAULT_15 DISABLE_BIT
#define DISABLE_FCRU_FAULT_16 DISABLE_BIT
#define DISABLE_FCRU_FAULT_17 DISABLE_BIT
#define DISABLE_FCRU_FAULT_18 DISABLE_BIT
#define DISABLE_FCRU_FAULT_19 DISABLE_BIT
#define DISABLE_FCRU_FAULT_20 DISABLE_BIT
#define DISABLE_FCRU_FAULT_21 DISABLE_BIT
#define DISABLE_FCRU_FAULT_22 DISABLE_BIT
#define DISABLE_FCRU_FAULT_23 DISABLE_BIT
#define DISABLE_FCRU_FAULT_24 DISABLE_BIT
#define DISABLE_FCRU_FAULT_25 DISABLE_BIT
#define DISABLE_FCRU_FAULT_26 DISABLE_BIT
#define DISABLE_FCRU_FAULT_27 DISABLE_BIT
#define DISABLE_FCRU_FAULT_28 DISABLE_BIT
#define DISABLE_FCRU_FAULT_29 DISABLE_BIT
#define DISABLE_FCRU_FAULT_30 DISABLE_BIT
#define DISABLE_FCRU_FAULT_31 DISABLE_BIT
#define DISABLE_FCRU_FAULT_32 DISABLE_BIT
#define DISABLE_FCRU_FAULT_33 DISABLE_BIT
#define DISABLE_FCRU_FAULT_34 DISABLE_BIT
#define DISABLE_FCRU_FAULT_35 DISABLE_BIT
#define DISABLE_FCRU_FAULT_36 DISABLE_BIT
#define DISABLE_FCRU_FAULT_37 DISABLE_BIT
#define DISABLE_FCRU_FAULT_38 DISABLE_BIT
#define DISABLE_FCRU_FAULT_39 DISABLE_BIT
#define DISABLE_FCRU_FAULT_40 DISABLE_BIT
#define DISABLE_FCRU_FAULT_41 DISABLE_BIT
#define DISABLE_FCRU_FAULT_42 DISABLE_BIT
#define DISABLE_FCRU_FAULT_43 DISABLE_BIT
#define DISABLE_FCRU_FAULT_44 DISABLE_BIT
#define DISABLE_FCRU_FAULT_45 DISABLE_BIT
#define DISABLE_FCRU_FAULT_46 DISABLE_BIT
#define DISABLE_FCRU_FAULT_47 DISABLE_BIT
#define DISABLE_FCRU_FAULT_48 DISABLE_BIT
#define DISABLE_FCRU_FAULT_49 DISABLE_BIT
#define DISABLE_FCRU_FAULT_50 DISABLE_BIT
#define DISABLE_FCRU_FAULT_51 DISABLE_BIT
#define DISABLE_FCRU_FAULT_52 DISABLE_BIT
#define DISABLE_FCRU_FAULT_53 DISABLE_BIT
#define DISABLE_FCRU_FAULT_54 DISABLE_BIT
#define DISABLE_FCRU_FAULT_55 DISABLE_BIT
#define DISABLE_FCRU_FAULT_56 DISABLE_BIT
#define DISABLE_FCRU_FAULT_57 DISABLE_BIT
#define DISABLE_FCRU_FAULT_58 DISABLE_BIT
#define DISABLE_FCRU_FAULT_59 DISABLE_BIT
#define DISABLE_FCRU_FAULT_60 DISABLE_BIT
#define DISABLE_FCRU_FAULT_61 DISABLE_BIT
#define DISABLE_FCRU_FAULT_62 DISABLE_BIT
#define DISABLE_FCRU_FAULT_63 DISABLE_BIT

#ifndef UNIT_TEST
   /* Macro to Update Register Value with Given Configuration */
   #define CONFIG_FCRU_RST_EN_00(Value)  (FCRU_CTRL_02_ADDR = Value)
   #define CONFIG_FCRU_RST_EN_01(Value)  (FCRU_CTRL_03_ADDR = Value)
   #define CONFIG_FCRU_PIN_EN_00(Value)  (FCRU_CTRL_00_ADDR = Value)
   #define CONFIG_FCRU_PIN_EN_01(Value)  (FCRU_CTRL_01_ADDR = Value)
   #define CONFIG_FCRU_CAP_BYP_00(Value) (FCRU_CTRL_08_ADDR = Value)
   #define CONFIG_FCRU_CAP_BYP_01(Value) (FCRU_CTRL_09_ADDR = Value)
   #define CONFIG_PMU_FAULTB_PIN(Value)  (FCRU_CTRL_10_ADDR = Value)

   /* Macro to Clear Fault Status */
   #define CLEAR_RST_EN_FAULT_STATE(fault_bit)                                                                                    \
      fault_bit > 31 ? (FCRU_CTRL_07_ADDR |= (ENABLE_BIT << (fault_bit - 32U))) :                                                 \
                       (FCRU_CTRL_06_ADDR |= (ENABLE_BIT << fault_bit)) /* Writing 1 to Bitx clears the fault */
   #define CLEAR_PIN_EN_FAULT_STATE(fault_bit)                                                                                    \
      fault_bit > 31 ? (FCRU_CTRL_05_ADDR |= (ENABLE_BIT << (fault_bit - 32U))) :                                                 \
                       (FCRU_CTRL_04_ADDR |= (ENABLE_BIT << fault_bit)) /* Writing 1 to Bitx clears the fault */

   /* Macro to read Data from FCRU DIAG Register */
   #define FCRU_CTRL_ADDR(Reg_info)                                                                                               \
      (Reg_info == 0 ? FCRU_DIAG_00_ADDR :                                                                                        \
                       (Reg_info == 1 ? FCRU_DIAG_01_ADDR : (Reg_info == 2 ? FCRU_DIAG_02_ADDR : FCRU_DIAG_03_ADDR)))

   /* Macro for Fault Injection */
   #define INJECT_FCRU_FAULT(fault_bit)                                                                                           \
      fault_bit > 31 ? (FCRU_CTRL_12_ADDR |= (ENABLE_BIT << (fault_bit - 32U))) :                                                 \
                       (FCRU_CTRL_11_ADDR |= (ENABLE_BIT << fault_bit)) /* Writing 1 to Bitx injects the fault */
#endif

/* Power-On LBIST register definition and PASS criteria */
#ifndef LBIST_SEQ_STAT0_ADDR
   #define LBIST_SEQ_STAT0_ADDR (0x89000058U)
#endif

/* Bit positions */
#ifndef STS_LBSC_LOADED_POS
   #define STS_LBSC_LOADED_POS (0U)
#endif

#ifndef STS_LBSC_DONE_POS
   #define STS_LBSC_DONE_POS (1U)
#endif

/* Bit masks */
#ifndef STS_LBSC_LOADED_MASK
   #define STS_LBSC_LOADED_MASK (1U << STS_LBSC_LOADED_POS)
#endif

#ifndef STS_LBSC_DONE_MASK
   #define STS_LBSC_DONE_MASK (1U << STS_LBSC_DONE_POS)
#endif

#define LBIST_AVAILABLE (STS_LBSC_DONE_MASK | STS_LBSC_LOADED_MASK)

/*===========================================================================*\
 * Variable Declarations
\*===========================================================================*/

typedef struct FCRU_Diag_Info
{
   uint32 Diag_Rst_En_00;
   uint32 Diag_Rst_En_01;
   uint32 Diag_Pin_En_00;
   uint32 Diag_Pin_En_01;
} FCRU_Diag_Info_t;

/*===========================================================================*\
 * Function Prototypes
\*===========================================================================*/
#if 0
static void Clear_FCRU_Fault_Status(uint8 reaction,uint8 fault_num);
static void Get_FCRU_Fault_Info(FCRU_Diag_Info_t *diag_reg_info);
#endif
void Inject_FCRU_Fault(uint8 fault_num);
static uint8 Get_Fault_Number(uint32 diag_reg);
static void Log_Last_FCRU_Reset_Reason(void);
static void Get_FCRU_Fault_Info(FCRU_Diag_Info_t *diag_reg_info);
void FCRU_Clear_All_Fault_Status(void);
/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *  Date        Name   (Description on following lines: SCR #, etc.)
 * --------     -----   ---------------------------------------------
 *
\*===========================================================================*/

#endif /* } SWC_PLT_CDD_FCRU_H */
