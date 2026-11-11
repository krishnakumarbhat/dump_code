#ifndef SWC_PLT_CDD_FCRU_CFG_H
#define SWC_PLT_CDD_FCRU_CFG_H
/*===========================================================================*\
 * FILE: SWC_PLT_CDD_FCRU_Cfg.h
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
#include "SWC_PLT_CDD_FCRU.h"
/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

/* Configuration Macros : FCRU Fault Reaction = Self Reset   */
#define RST_ENA_CONFIG_FAULT_00 ENABLE_FCRU_FAULT_00  /* Undervoltage detected on 0.8V VDD.    */
#define RST_ENA_CONFIG_FAULT_01 ENABLE_FCRU_FAULT_01  /* Undervoltage detected on 1.8V VDDIO.    */
#define RST_ENA_CONFIG_FAULT_02 ENABLE_FCRU_FAULT_02  /* Reference clock failure detected.    */
#define RST_ENA_CONFIG_FAULT_03 ENABLE_FCRU_FAULT_03  /* PLL lock lost.    */
#define RST_ENA_CONFIG_FAULT_04 ENABLE_FCRU_FAULT_04  /* PVT0 temperature alarm exceeded threshold.    */
#define RST_ENA_CONFIG_FAULT_05 ENABLE_FCRU_FAULT_05  /* PVT1 temperature alarm exceeded threshold.    */
#define RST_ENA_CONFIG_FAULT_06 DISABLE_FCRU_FAULT_06 /* BIST controller detected failure.    */
#define RST_ENA_CONFIG_FAULT_07 DISABLE_FCRU_FAULT_07 /* Watchdog timeout.    */
#define RST_ENA_CONFIG_FAULT_08 ENABLE_FCRU_FAULT_08  /* R52 internal dual-core lockstep check failure 0.    */
#define RST_ENA_CONFIG_FAULT_09 ENABLE_FCRU_FAULT_09  /* R52 internal dual-core lockstep check failure 1.    */
#define RST_ENA_CONFIG_FAULT_10 ENABLE_FCRU_FAULT_10  /* R52 internal dual-core lockstep check failure 2.    */
#define RST_ENA_CONFIG_FAULT_11 ENABLE_FCRU_FAULT_11  /* R52 internal dual-core lockstep check failure 3.    */
#define RST_ENA_CONFIG_FAULT_12 ENABLE_FCRU_FAULT_12  /* R52 internal dual-core lockstep check failure 4.    */
#define RST_ENA_CONFIG_FAULT_13 ENABLE_FCRU_FAULT_13  /* R52 internal dual-core lockstep check failure 5.    */
#define RST_ENA_CONFIG_FAULT_14 ENABLE_FCRU_FAULT_14  /* R52 internal dual-core lockstep check failure 6.    */
#define RST_ENA_CONFIG_FAULT_15 ENABLE_FCRU_FAULT_15  /* R52 internal dual-core lockstep check failure 7.    */
#define RST_ENA_CONFIG_FAULT_16 ENABLE_FCRU_FAULT_16  /* R52 internal dual-core lockstep check failure 8.    */
#define RST_ENA_CONFIG_FAULT_17 ENABLE_FCRU_FAULT_17  /* R52 internal dual-core lockstep check failure 9.    */
#if (ENABLE_DEBUGGING != STD_ON) /* enable debug signal related faults reaction only when debugging is disabled */
   #define RST_ENA_CONFIG_FAULT_18 ENABLE_FCRU_FAULT_18 /* R52 internal dual-core lockstep check failure 10.    */
   #define RST_ENA_CONFIG_FAULT_19 ENABLE_FCRU_FAULT_19 /* R52 internal dual-core lockstep check failure 11.    */
   #define RST_ENA_CONFIG_FAULT_20 ENABLE_FCRU_FAULT_20 /* R52 internal dual-core lockstep check failure 12.    */
   #define RST_ENA_CONFIG_FAULT_21 ENABLE_FCRU_FAULT_21 /* R52 internal dual-core lockstep check failure 13.    */
#else
   #define RST_ENA_CONFIG_FAULT_18 DISABLE_FCRU_FAULT_18 /* R52 internal dual-core lockstep check failure 10.    */
   #define RST_ENA_CONFIG_FAULT_19 DISABLE_FCRU_FAULT_19 /* R52 internal dual-core lockstep check failure 11.    */
   #define RST_ENA_CONFIG_FAULT_20 DISABLE_FCRU_FAULT_20 /* R52 internal dual-core lockstep check failure 12.    */
   #define RST_ENA_CONFIG_FAULT_21 DISABLE_FCRU_FAULT_21 /* R52 internal dual-core lockstep check failure 13.    */
#endif
#define RST_ENA_CONFIG_FAULT_22 ENABLE_FCRU_FAULT_22  /* R52 internal dual-core lockstep check failure 14.    */
#define RST_ENA_CONFIG_FAULT_23 ENABLE_FCRU_FAULT_23  /* R52 internal dual-core lockstep check failure 15.    */
#define RST_ENA_CONFIG_FAULT_24 ENABLE_FCRU_FAULT_24  /* R52 internal dual-core lockstep check failure 16.    */
#define RST_ENA_CONFIG_FAULT_25 ENABLE_FCRU_FAULT_25  /* R52 internal dual-core lockstep check failure 17.    */
#define RST_ENA_CONFIG_FAULT_26 DISABLE_FCRU_FAULT_26 /* R52 correctable AXIS data error.    */
#define RST_ENA_CONFIG_FAULT_27 ENABLE_FCRU_FAULT_27  /* R52 uncorrectable AXIS data error.    */
#define RST_ENA_CONFIG_FAULT_28 ENABLE_FCRU_FAULT_28  /* R52 fatal AXIS handshake error.    */
#define RST_ENA_CONFIG_FAULT_29 ENABLE_FCRU_FAULT_29  /* R52 fatal AXIS data error.    */
#define RST_ENA_CONFIG_FAULT_30 ENABLE_FCRU_FAULT_30  /* R52 fatal AXIS control error     */
#define RST_ENA_CONFIG_FAULT_31 DISABLE_FCRU_FAULT_31 /* R52 correctable L1 cache or TCM error.    */
#define RST_ENA_CONFIG_FAULT_32 ENABLE_FCRU_FAULT_32  /* R52 fatal memory error from TCMs.    */
#define RST_ENA_CONFIG_FAULT_33 DISABLE_FCRU_FAULT_33 /* R52 correctable AXIM data error.    */
#define RST_ENA_CONFIG_FAULT_34 ENABLE_FCRU_FAULT_34  /* R52 fatal AXIM data error.    */
#define RST_ENA_CONFIG_FAULT_35 ENABLE_FCRU_FAULT_35  /* R52 fatal AXIM handshake error.    */
#define RST_ENA_CONFIG_FAULT_36 ENABLE_FCRU_FAULT_36  /* R52 fatal AXIM data error.    */
#define RST_ENA_CONFIG_FAULT_37 ENABLE_FCRU_FAULT_37  /* R52 fatal AXIM control error.    */
#define RST_ENA_CONFIG_FAULT_38 DISABLE_FCRU_FAULT_38 /* R52 correctable L1 instruction cache error.    */
#define RST_ENA_CONFIG_FAULT_39 DISABLE_FCRU_FAULT_39 /* R52 correctable L1 data cache error.    */
#define RST_ENA_CONFIG_FAULT_40 DISABLE_FCRU_FAULT_40 /* R52 correctable TCM error.    */
#define RST_ENA_CONFIG_FAULT_41 ENABLE_FCRU_FAULT_41  /* R52 fatal TCM error.    */
#define RST_ENA_CONFIG_FAULT_42 ENABLE_FCRU_FAULT_42  /* R52 AXIM timeout.    */
#define RST_ENA_CONFIG_FAULT_43 DISABLE_FCRU_FAULT_43 /* R52 correctable L1 cache or TCM error.    */
#define RST_ENA_CONFIG_FAULT_44 ENABLE_FCRU_FAULT_44  /* R52 fatal L1 or TCM error.    */
#define RST_ENA_CONFIG_FAULT_45 DISABLE_FCRU_FAULT_45 /* R52 interrupt masked in Hypervisor mode timeout.    */
#define RST_ENA_CONFIG_FAULT_46 DISABLE_FCRU_FAULT_46 /* R52 fatal memory or bus error in Hypervisor mode.    */
#define RST_ENA_CONFIG_FAULT_47 DISABLE_FCRU_FAULT_47 /* R52 EL2 MPU memory access violation.    */
#define RST_ENA_CONFIG_FAULT_48 DISABLE_FCRU_FAULT_48 /* R52 EL1 MPU memory access violation.    */
#define RST_ENA_CONFIG_FAULT_49 DISABLE_FCRU_FAULT_49 /* R52 internal exception.    */
#define RST_ENA_CONFIG_FAULT_50 DISABLE_FCRU_FAULT_50 /* R52 memory access EL1 MPU - EL2 MPU conflict.    */
#define RST_ENA_CONFIG_FAULT_51 DISABLE_FCRU_FAULT_51 /* R52 livelock due to hard error or exception vector.    */
#define RST_ENA_CONFIG_FAULT_52 DISABLE_FCRU_FAULT_52 /* R52 EL2 software unlocked IMP_TESTR1.  */
#define RST_ENA_CONFIG_FAULT_53 DISABLE_FCRU_FAULT_53 /* RT640 safety error.    */
#define RST_ENA_CONFIG_FAULT_54 DISABLE_FCRU_FAULT_54 /* OTP read failure.    */
#define RST_ENA_CONFIG_FAULT_55 ENABLE_FCRU_FAULT_55  /* Artie NOC (Artie Core NOC) fault detected.    */
#define RST_ENA_CONFIG_FAULT_56 DISABLE_FCRU_FAULT_56 /* Reserved.    */
#define RST_ENA_CONFIG_FAULT_57 ENABLE_FCRU_FAULT_57  /* Chandra NOC fault detected.    */
#define RST_ENA_CONFIG_FAULT_58 ENABLE_FCRU_FAULT_58  /* Small NOC (Artie wrapper NOC) fault detected.    */
#define RST_ENA_CONFIG_FAULT_59 DISABLE_FCRU_FAULT_59 /* Reserved.    */
#define RST_ENA_CONFIG_FAULT_60 DISABLE_FCRU_FAULT_60 /* Reserved.    */
#define RST_ENA_CONFIG_FAULT_61 ENABLE_FCRU_FAULT_61  /* Reset fault for system reset.    */
#define RST_ENA_CONFIG_FAULT_62 ENABLE_FCRU_FAULT_62  /* Reset fault for R52 core reset.    */
#define RST_ENA_CONFIG_FAULT_63 ENABLE_FCRU_FAULT_63  /* Reset fault for R52 top reset.    */

/* Configuration Macros : FCRU Fault Reaction = PMU_FAULTB ACTIVE   */
#define PIN_ENA_CONFIG_FAULT_00 ENABLE_FCRU_FAULT_00  /* Undervoltage detected on 0.8V VDD.    */
#define PIN_ENA_CONFIG_FAULT_01 ENABLE_FCRU_FAULT_01  /* Undervoltage detected on 1.8V VDDIO.    */
#define PIN_ENA_CONFIG_FAULT_02 ENABLE_FCRU_FAULT_02  /* Reference clock failure detected.    */
#define PIN_ENA_CONFIG_FAULT_03 ENABLE_FCRU_FAULT_03  /* PLL lock lost.    */
#define PIN_ENA_CONFIG_FAULT_04 ENABLE_FCRU_FAULT_04  /* PVT0 temperature alarm exceeded threshold.    */
#define PIN_ENA_CONFIG_FAULT_05 ENABLE_FCRU_FAULT_05  /* PVT1 temperature alarm exceeded threshold.    */
#define PIN_ENA_CONFIG_FAULT_06 DISABLE_FCRU_FAULT_06 /* BIST controller detected failure.    */
#define PIN_ENA_CONFIG_FAULT_07 DISABLE_FCRU_FAULT_07 /* Watchdog timeout.    */
#define PIN_ENA_CONFIG_FAULT_08 ENABLE_FCRU_FAULT_08  /* R52 internal dual-core lockstep check failure 0.    */
#define PIN_ENA_CONFIG_FAULT_09 ENABLE_FCRU_FAULT_09  /* R52 internal dual-core lockstep check failure 1.    */
#define PIN_ENA_CONFIG_FAULT_10 ENABLE_FCRU_FAULT_10  /* R52 internal dual-core lockstep check failure 2.    */
#define PIN_ENA_CONFIG_FAULT_11 ENABLE_FCRU_FAULT_11  /* R52 internal dual-core lockstep check failure 3.    */
#define PIN_ENA_CONFIG_FAULT_12 ENABLE_FCRU_FAULT_12  /* R52 internal dual-core lockstep check failure 4.    */
#define PIN_ENA_CONFIG_FAULT_13 ENABLE_FCRU_FAULT_13  /* R52 internal dual-core lockstep check failure 5.    */
#define PIN_ENA_CONFIG_FAULT_14 ENABLE_FCRU_FAULT_14  /* R52 internal dual-core lockstep check failure 6.    */
#define PIN_ENA_CONFIG_FAULT_15 ENABLE_FCRU_FAULT_15  /* R52 internal dual-core lockstep check failure 7.    */
#define PIN_ENA_CONFIG_FAULT_16 ENABLE_FCRU_FAULT_16  /* R52 internal dual-core lockstep check failure 8.    */
#define PIN_ENA_CONFIG_FAULT_17 ENABLE_FCRU_FAULT_17  /* R52 internal dual-core lockstep check failure 9.    */
#if (ENABLE_DEBUGGING != STD_ON) /* enable debug signal related faults reaction only when debugging is disabled */
   #define PIN_ENA_CONFIG_FAULT_18 ENABLE_FCRU_FAULT_18 /* R52 internal dual-core lockstep check failure 10.    */
   #define PIN_ENA_CONFIG_FAULT_19 ENABLE_FCRU_FAULT_19 /* R52 internal dual-core lockstep check failure 11.    */
   #define PIN_ENA_CONFIG_FAULT_20 ENABLE_FCRU_FAULT_20 /* R52 internal dual-core lockstep check failure 12.    */
   #define PIN_ENA_CONFIG_FAULT_21 ENABLE_FCRU_FAULT_21 /* R52 internal dual-core lockstep check failure 13.    */
#else
   #define PIN_ENA_CONFIG_FAULT_18 DISABLE_FCRU_FAULT_18 /* R52 internal dual-core lockstep check failure 10.    */
   #define PIN_ENA_CONFIG_FAULT_19 DISABLE_FCRU_FAULT_19 /* R52 internal dual-core lockstep check failure 11.    */
   #define PIN_ENA_CONFIG_FAULT_20 DISABLE_FCRU_FAULT_20 /* R52 internal dual-core lockstep check failure 12.    */
   #define PIN_ENA_CONFIG_FAULT_21 DISABLE_FCRU_FAULT_21 /* R52 internal dual-core lockstep check failure 13.    */
#endif
#define PIN_ENA_CONFIG_FAULT_22 ENABLE_FCRU_FAULT_22  /* R52 internal dual-core lockstep check failure 14.    */
#define PIN_ENA_CONFIG_FAULT_23 ENABLE_FCRU_FAULT_23  /* R52 internal dual-core lockstep check failure 15.    */
#define PIN_ENA_CONFIG_FAULT_24 ENABLE_FCRU_FAULT_24  /* R52 internal dual-core lockstep check failure 16.    */
#define PIN_ENA_CONFIG_FAULT_25 ENABLE_FCRU_FAULT_25  /* R52 internal dual-core lockstep check failure 17.    */
#define PIN_ENA_CONFIG_FAULT_26 DISABLE_FCRU_FAULT_26 /* R52 correctable AXIS data error.    */
#define PIN_ENA_CONFIG_FAULT_27 ENABLE_FCRU_FAULT_27  /* R52 uncorrectable AXIS data error.    */
#define PIN_ENA_CONFIG_FAULT_28 ENABLE_FCRU_FAULT_28  /* R52 fatal AXIS handshake error.    */
#define PIN_ENA_CONFIG_FAULT_29 ENABLE_FCRU_FAULT_29  /* R52 fatal AXIS data error.    */
#define PIN_ENA_CONFIG_FAULT_30 ENABLE_FCRU_FAULT_30  /* R52 fatal AXIS control error.    */
#define PIN_ENA_CONFIG_FAULT_31 DISABLE_FCRU_FAULT_31 /* R52 correctable L1 cache or TCM error.    */
#define PIN_ENA_CONFIG_FAULT_32 ENABLE_FCRU_FAULT_32  /* R52 fatal memory error from TCMs.    */
#define PIN_ENA_CONFIG_FAULT_33 DISABLE_FCRU_FAULT_33 /* R52 correctable AXIM data error.    */
#define PIN_ENA_CONFIG_FAULT_34 ENABLE_FCRU_FAULT_34  /* R52 fatal AXIM data error.    */
#define PIN_ENA_CONFIG_FAULT_35 ENABLE_FCRU_FAULT_35  /* R52 fatal AXIM handshake error.    */
#define PIN_ENA_CONFIG_FAULT_36 ENABLE_FCRU_FAULT_36  /* R52 fatal AXIM data error.    */
#define PIN_ENA_CONFIG_FAULT_37 ENABLE_FCRU_FAULT_37  /* R52 fatal AXIM control error.    */
#define PIN_ENA_CONFIG_FAULT_38 DISABLE_FCRU_FAULT_38 /* R52 correctable L1 instruction cache error.    */
#define PIN_ENA_CONFIG_FAULT_39 DISABLE_FCRU_FAULT_39 /* R52 correctable L1 data cache error.    */
#define PIN_ENA_CONFIG_FAULT_40 DISABLE_FCRU_FAULT_40 /* R52 correctable TCM error.    */
#define PIN_ENA_CONFIG_FAULT_41 ENABLE_FCRU_FAULT_41  /* R52 fatal TCM error.    */
#define PIN_ENA_CONFIG_FAULT_42 ENABLE_FCRU_FAULT_42  /* R52 AXIM timeout.    */
#define PIN_ENA_CONFIG_FAULT_43 DISABLE_FCRU_FAULT_43 /* R52 correctable L1 cache or TCM error.    */
#define PIN_ENA_CONFIG_FAULT_44 ENABLE_FCRU_FAULT_44  /* R52 fatal L1 or TCM error.    */
#define PIN_ENA_CONFIG_FAULT_45 DISABLE_FCRU_FAULT_45 /* R52 interrupt masked in Hypervisor mode timeout.    */
#define PIN_ENA_CONFIG_FAULT_46 DISABLE_FCRU_FAULT_46 /* R52 fatal memory or bus error in Hypervisor mode.    */
#define PIN_ENA_CONFIG_FAULT_47 DISABLE_FCRU_FAULT_47 /* R52 EL2 MPU memory access violation.    */
#define PIN_ENA_CONFIG_FAULT_48 DISABLE_FCRU_FAULT_48 /* R52 EL1 MPU memory access violation.    */
#define PIN_ENA_CONFIG_FAULT_49 DISABLE_FCRU_FAULT_49 /* R52 internal exception.    */
#define PIN_ENA_CONFIG_FAULT_50 DISABLE_FCRU_FAULT_50 /* R52 memory access EL1 MPU - EL2 MPU conflict.    */
#define PIN_ENA_CONFIG_FAULT_51 DISABLE_FCRU_FAULT_51 /* R52 livelock due to hard error or exception vector.    */
#define PIN_ENA_CONFIG_FAULT_52 DISABLE_FCRU_FAULT_52 /* R52 EL2 software unlocked IMP_TESTR1. */
#define PIN_ENA_CONFIG_FAULT_53 DISABLE_FCRU_FAULT_53 /* RT640 safety error.    */
#define PIN_ENA_CONFIG_FAULT_54 DISABLE_FCRU_FAULT_54 /* OTP read failure.    */
#define PIN_ENA_CONFIG_FAULT_55 ENABLE_FCRU_FAULT_55  /* Artie NOC (Artie Core NOC) fault detected.    */
#define PIN_ENA_CONFIG_FAULT_56 DISABLE_FCRU_FAULT_56 /* Reserved.    */
#define PIN_ENA_CONFIG_FAULT_57 ENABLE_FCRU_FAULT_57  /* Chandra NOC fault detected.    */
#define PIN_ENA_CONFIG_FAULT_58 ENABLE_FCRU_FAULT_58  /* Small NOC (Artie wrapper NOC) fault detected.    */
#define PIN_ENA_CONFIG_FAULT_59 DISABLE_FCRU_FAULT_59 /* Reserved.    */
#define PIN_ENA_CONFIG_FAULT_60 DISABLE_FCRU_FAULT_60 /* Reserved.    */
#define PIN_ENA_CONFIG_FAULT_61 ENABLE_FCRU_FAULT_61  /* Reset fault for system reset.    */
#define PIN_ENA_CONFIG_FAULT_62 ENABLE_FCRU_FAULT_62  /* Reset fault for R52 core reset.    */
#define PIN_ENA_CONFIG_FAULT_63 ENABLE_FCRU_FAULT_63  /* Reset fault for R52 top reset.    */

/* Configuration Macros : FCRU Fault Capture Bypass  */
#define CAP_BYP_CONFIG_FAULT_00 DISABLE_FCRU_FAULT_00 /* Undervoltage detected on 0.8V VDD.    */
#define CAP_BYP_CONFIG_FAULT_01 DISABLE_FCRU_FAULT_01 /* Undervoltage detected on 1.8V VDDIO.    */
#define CAP_BYP_CONFIG_FAULT_02 DISABLE_FCRU_FAULT_02 /* Reference clock failure detected.    */
#define CAP_BYP_CONFIG_FAULT_03 DISABLE_FCRU_FAULT_03 /* PLL lock lost.    */
#define CAP_BYP_CONFIG_FAULT_04 DISABLE_FCRU_FAULT_04 /* PVT0 temperature alarm exceeded threshold.    */
#define CAP_BYP_CONFIG_FAULT_05 DISABLE_FCRU_FAULT_05 /* PVT1 temperature alarm exceeded threshold.    */
#define CAP_BYP_CONFIG_FAULT_06 DISABLE_FCRU_FAULT_06 /* BIST controller detected failure.    */
#define CAP_BYP_CONFIG_FAULT_07 DISABLE_FCRU_FAULT_07 /* Watchdog timeout.    */
#define CAP_BYP_CONFIG_FAULT_08 DISABLE_FCRU_FAULT_08 /* R52 internal dual-core lockstep check failure 0.    */
#define CAP_BYP_CONFIG_FAULT_09 DISABLE_FCRU_FAULT_09 /* R52 internal dual-core lockstep check failure 1.    */
#define CAP_BYP_CONFIG_FAULT_10 DISABLE_FCRU_FAULT_10 /* R52 internal dual-core lockstep check failure 2.    */
#define CAP_BYP_CONFIG_FAULT_11 DISABLE_FCRU_FAULT_11 /* R52 internal dual-core lockstep check failure 3.    */
#define CAP_BYP_CONFIG_FAULT_12 DISABLE_FCRU_FAULT_12 /* R52 internal dual-core lockstep check failure 4.    */
#define CAP_BYP_CONFIG_FAULT_13 DISABLE_FCRU_FAULT_13 /* R52 internal dual-core lockstep check failure 5.    */
#define CAP_BYP_CONFIG_FAULT_14 DISABLE_FCRU_FAULT_14 /* R52 internal dual-core lockstep check failure 6.    */
#define CAP_BYP_CONFIG_FAULT_15 DISABLE_FCRU_FAULT_15 /* R52 internal dual-core lockstep check failure 7.    */
#define CAP_BYP_CONFIG_FAULT_16 DISABLE_FCRU_FAULT_16 /* R52 internal dual-core lockstep check failure 8.    */
#define CAP_BYP_CONFIG_FAULT_17 DISABLE_FCRU_FAULT_17 /* R52 internal dual-core lockstep check failure 9.    */
#define CAP_BYP_CONFIG_FAULT_18 DISABLE_FCRU_FAULT_18 /* R52 internal dual-core lockstep check failure 10.    */
#define CAP_BYP_CONFIG_FAULT_19 DISABLE_FCRU_FAULT_19 /* R52 internal dual-core lockstep check failure 11.    */
#define CAP_BYP_CONFIG_FAULT_20 DISABLE_FCRU_FAULT_20 /* R52 internal dual-core lockstep check failure 12.    */
#define CAP_BYP_CONFIG_FAULT_21 DISABLE_FCRU_FAULT_21 /* R52 internal dual-core lockstep check failure 13.    */
#define CAP_BYP_CONFIG_FAULT_22 DISABLE_FCRU_FAULT_22 /* R52 internal dual-core lockstep check failure 14.    */
#define CAP_BYP_CONFIG_FAULT_23 DISABLE_FCRU_FAULT_23 /* R52 internal dual-core lockstep check failure 15.    */
#define CAP_BYP_CONFIG_FAULT_24 DISABLE_FCRU_FAULT_24 /* R52 internal dual-core lockstep check failure 16.    */
#define CAP_BYP_CONFIG_FAULT_25 DISABLE_FCRU_FAULT_25 /* R52 internal dual-core lockstep check failure 17.    */
#define CAP_BYP_CONFIG_FAULT_26 DISABLE_FCRU_FAULT_26 /* R52 correctable AXIS data error.    */
#define CAP_BYP_CONFIG_FAULT_27 DISABLE_FCRU_FAULT_27 /* R52 uncorrectable AXIS data error.    */
#define CAP_BYP_CONFIG_FAULT_28 DISABLE_FCRU_FAULT_28 /* R52 fatal AXIS handshake error.    */
#define CAP_BYP_CONFIG_FAULT_29 DISABLE_FCRU_FAULT_29 /* R52 fatal AXIS data error.    */
#define CAP_BYP_CONFIG_FAULT_30 DISABLE_FCRU_FAULT_30 /* R52 fatal AXIS control error.    */
#define CAP_BYP_CONFIG_FAULT_31 DISABLE_FCRU_FAULT_31 /* R52 correctable L1 cache or TCM error.    */
#define CAP_BYP_CONFIG_FAULT_32 DISABLE_FCRU_FAULT_32 /* R52 fatal memory error from TCMs.    */
#define CAP_BYP_CONFIG_FAULT_33 DISABLE_FCRU_FAULT_33 /* R52 correctable AXIM data error.    */
#define CAP_BYP_CONFIG_FAULT_34 DISABLE_FCRU_FAULT_34 /* R52 fatal AXIM data error.    */
#define CAP_BYP_CONFIG_FAULT_35 DISABLE_FCRU_FAULT_35 /* R52 fatal AXIM handshake error.    */
#define CAP_BYP_CONFIG_FAULT_36 DISABLE_FCRU_FAULT_36 /* R52 fatal AXIM data error.    */
#define CAP_BYP_CONFIG_FAULT_37 DISABLE_FCRU_FAULT_37 /* R52 fatal AXIM control error.    */
#define CAP_BYP_CONFIG_FAULT_38 DISABLE_FCRU_FAULT_38 /* R52 correctable L1 instruction cache error.    */
#define CAP_BYP_CONFIG_FAULT_39 DISABLE_FCRU_FAULT_39 /* R52 correctable L1 data cache error.    */
#define CAP_BYP_CONFIG_FAULT_40 DISABLE_FCRU_FAULT_40 /* R52 correctable TCM error.    */
#define CAP_BYP_CONFIG_FAULT_41 DISABLE_FCRU_FAULT_41 /* R52 fatal TCM error.    */
#define CAP_BYP_CONFIG_FAULT_42 DISABLE_FCRU_FAULT_42 /* R52 AXIM timeout.    */
#define CAP_BYP_CONFIG_FAULT_43 DISABLE_FCRU_FAULT_43 /* R52 correctable L1 cache or TCM error.    */
#define CAP_BYP_CONFIG_FAULT_44 DISABLE_FCRU_FAULT_44 /* R52 fatal L1 or TCM error.    */
#define CAP_BYP_CONFIG_FAULT_45 DISABLE_FCRU_FAULT_45 /* R52 interrupt masked in Hypervisor mode timeout.    */
#define CAP_BYP_CONFIG_FAULT_46 DISABLE_FCRU_FAULT_46 /* R52 fatal memory or bus error in Hypervisor mode.    */
#define CAP_BYP_CONFIG_FAULT_47 DISABLE_FCRU_FAULT_47 /* R52 EL2 MPU memory access violation.    */
#define CAP_BYP_CONFIG_FAULT_48 DISABLE_FCRU_FAULT_48 /* R52 EL1 MPU memory access violation.    */
#define CAP_BYP_CONFIG_FAULT_49 DISABLE_FCRU_FAULT_49 /* R52 internal exception.    */
#define CAP_BYP_CONFIG_FAULT_50 DISABLE_FCRU_FAULT_50 /* R52 memory access EL1 MPU - EL2 MPU conflict.    */
#define CAP_BYP_CONFIG_FAULT_51 DISABLE_FCRU_FAULT_51 /* R52 livelock due to hard error or exception vector.    */
#define CAP_BYP_CONFIG_FAULT_52 DISABLE_FCRU_FAULT_52 /* R52 EL2 software unlocked IMP_TESTR1 */
#define CAP_BYP_CONFIG_FAULT_53 DISABLE_FCRU_FAULT_53 /* RT640 safety error.    */
#define CAP_BYP_CONFIG_FAULT_54 DISABLE_FCRU_FAULT_54 /* OTP read failure.    */
#define CAP_BYP_CONFIG_FAULT_55 DISABLE_FCRU_FAULT_55 /* Artie NOC (Artie Core NOC) fault detected.    */
#define CAP_BYP_CONFIG_FAULT_56 DISABLE_FCRU_FAULT_56 /* Reserved.    */
#define CAP_BYP_CONFIG_FAULT_57 DISABLE_FCRU_FAULT_57 /* Chandra NOC fault detected.    */
#define CAP_BYP_CONFIG_FAULT_58 DISABLE_FCRU_FAULT_58 /* Small NOC (Artie wrapper NOC) fault detected.    */
#define CAP_BYP_CONFIG_FAULT_59 DISABLE_FCRU_FAULT_59 /* Reserved.    */
#define CAP_BYP_CONFIG_FAULT_60 DISABLE_FCRU_FAULT_60 /* Reserved.    */
#define CAP_BYP_CONFIG_FAULT_61 DISABLE_FCRU_FAULT_61 /* Reset fault for system reset.    */
#define CAP_BYP_CONFIG_FAULT_62 DISABLE_FCRU_FAULT_62 /* Reset fault for R52 core reset.    */
#define CAP_BYP_CONFIG_FAULT_63 DISABLE_FCRU_FAULT_63 /* Reset fault for R52 top reset.    */

#define RST_ENA_CONFIG0                                                                                                           \
   (RST_ENA_CONFIG_FAULT_00 | RST_ENA_CONFIG_FAULT_01 | RST_ENA_CONFIG_FAULT_02 | RST_ENA_CONFIG_FAULT_03 |                       \
    RST_ENA_CONFIG_FAULT_04 | RST_ENA_CONFIG_FAULT_05 | RST_ENA_CONFIG_FAULT_06 | RST_ENA_CONFIG_FAULT_07 |                       \
    RST_ENA_CONFIG_FAULT_08 | RST_ENA_CONFIG_FAULT_09 | RST_ENA_CONFIG_FAULT_10 | RST_ENA_CONFIG_FAULT_11 |                       \
    RST_ENA_CONFIG_FAULT_12 | RST_ENA_CONFIG_FAULT_13 | RST_ENA_CONFIG_FAULT_14 | RST_ENA_CONFIG_FAULT_15 |                       \
    RST_ENA_CONFIG_FAULT_16 | RST_ENA_CONFIG_FAULT_17 | RST_ENA_CONFIG_FAULT_18 | RST_ENA_CONFIG_FAULT_19 |                       \
    RST_ENA_CONFIG_FAULT_20 | RST_ENA_CONFIG_FAULT_21 | RST_ENA_CONFIG_FAULT_22 | RST_ENA_CONFIG_FAULT_23 |                       \
    RST_ENA_CONFIG_FAULT_24 | RST_ENA_CONFIG_FAULT_25 | RST_ENA_CONFIG_FAULT_26 | RST_ENA_CONFIG_FAULT_27 |                       \
    RST_ENA_CONFIG_FAULT_28 | RST_ENA_CONFIG_FAULT_29 | RST_ENA_CONFIG_FAULT_30 | RST_ENA_CONFIG_FAULT_31)

#define RST_ENA_CONFIG1                                                                                                           \
   (RST_ENA_CONFIG_FAULT_32 | RST_ENA_CONFIG_FAULT_33 | RST_ENA_CONFIG_FAULT_34 | RST_ENA_CONFIG_FAULT_35 |                       \
    RST_ENA_CONFIG_FAULT_36 | RST_ENA_CONFIG_FAULT_37 | RST_ENA_CONFIG_FAULT_38 | RST_ENA_CONFIG_FAULT_39 |                       \
    RST_ENA_CONFIG_FAULT_40 | RST_ENA_CONFIG_FAULT_41 | RST_ENA_CONFIG_FAULT_42 | RST_ENA_CONFIG_FAULT_43 |                       \
    RST_ENA_CONFIG_FAULT_44 | RST_ENA_CONFIG_FAULT_45 | RST_ENA_CONFIG_FAULT_46 | RST_ENA_CONFIG_FAULT_47 |                       \
    RST_ENA_CONFIG_FAULT_48 | RST_ENA_CONFIG_FAULT_49 | RST_ENA_CONFIG_FAULT_50 | RST_ENA_CONFIG_FAULT_51 |                       \
    RST_ENA_CONFIG_FAULT_52 | RST_ENA_CONFIG_FAULT_53 | RST_ENA_CONFIG_FAULT_54 | RST_ENA_CONFIG_FAULT_55 |                       \
    RST_ENA_CONFIG_FAULT_56 | RST_ENA_CONFIG_FAULT_57 | RST_ENA_CONFIG_FAULT_58 | RST_ENA_CONFIG_FAULT_59 |                       \
    RST_ENA_CONFIG_FAULT_60 | RST_ENA_CONFIG_FAULT_61 | RST_ENA_CONFIG_FAULT_62 | RST_ENA_CONFIG_FAULT_63)

#define PIN_ENA_CONFIG0                                                                                                           \
   (PIN_ENA_CONFIG_FAULT_00 | PIN_ENA_CONFIG_FAULT_01 | PIN_ENA_CONFIG_FAULT_02 | PIN_ENA_CONFIG_FAULT_03 |                       \
    PIN_ENA_CONFIG_FAULT_04 | PIN_ENA_CONFIG_FAULT_05 | PIN_ENA_CONFIG_FAULT_06 | PIN_ENA_CONFIG_FAULT_07 |                       \
    PIN_ENA_CONFIG_FAULT_08 | PIN_ENA_CONFIG_FAULT_09 | PIN_ENA_CONFIG_FAULT_10 | PIN_ENA_CONFIG_FAULT_11 |                       \
    PIN_ENA_CONFIG_FAULT_12 | PIN_ENA_CONFIG_FAULT_13 | PIN_ENA_CONFIG_FAULT_14 | PIN_ENA_CONFIG_FAULT_15 |                       \
    PIN_ENA_CONFIG_FAULT_16 | PIN_ENA_CONFIG_FAULT_17 | PIN_ENA_CONFIG_FAULT_18 | PIN_ENA_CONFIG_FAULT_19 |                       \
    PIN_ENA_CONFIG_FAULT_20 | PIN_ENA_CONFIG_FAULT_21 | PIN_ENA_CONFIG_FAULT_22 | PIN_ENA_CONFIG_FAULT_23 |                       \
    PIN_ENA_CONFIG_FAULT_24 | PIN_ENA_CONFIG_FAULT_25 | PIN_ENA_CONFIG_FAULT_26 | PIN_ENA_CONFIG_FAULT_27 |                       \
    PIN_ENA_CONFIG_FAULT_28 | PIN_ENA_CONFIG_FAULT_29 | PIN_ENA_CONFIG_FAULT_30 | PIN_ENA_CONFIG_FAULT_31)

#define PIN_ENA_CONFIG1                                                                                                           \
   (PIN_ENA_CONFIG_FAULT_32 | PIN_ENA_CONFIG_FAULT_33 | PIN_ENA_CONFIG_FAULT_34 | PIN_ENA_CONFIG_FAULT_35 |                       \
    PIN_ENA_CONFIG_FAULT_36 | PIN_ENA_CONFIG_FAULT_37 | PIN_ENA_CONFIG_FAULT_38 | PIN_ENA_CONFIG_FAULT_39 |                       \
    PIN_ENA_CONFIG_FAULT_40 | PIN_ENA_CONFIG_FAULT_41 | PIN_ENA_CONFIG_FAULT_42 | PIN_ENA_CONFIG_FAULT_43 |                       \
    PIN_ENA_CONFIG_FAULT_44 | PIN_ENA_CONFIG_FAULT_45 | PIN_ENA_CONFIG_FAULT_46 | PIN_ENA_CONFIG_FAULT_47 |                       \
    PIN_ENA_CONFIG_FAULT_48 | PIN_ENA_CONFIG_FAULT_49 | PIN_ENA_CONFIG_FAULT_50 | PIN_ENA_CONFIG_FAULT_51 |                       \
    PIN_ENA_CONFIG_FAULT_52 | PIN_ENA_CONFIG_FAULT_53 | PIN_ENA_CONFIG_FAULT_54 | PIN_ENA_CONFIG_FAULT_55 |                       \
    PIN_ENA_CONFIG_FAULT_56 | PIN_ENA_CONFIG_FAULT_57 | PIN_ENA_CONFIG_FAULT_58 | PIN_ENA_CONFIG_FAULT_59 |                       \
    PIN_ENA_CONFIG_FAULT_60 | PIN_ENA_CONFIG_FAULT_61 | PIN_ENA_CONFIG_FAULT_62 | PIN_ENA_CONFIG_FAULT_63)

#define CAP_BYP_CONFIG0                                                                                                           \
   (CAP_BYP_CONFIG_FAULT_00 | CAP_BYP_CONFIG_FAULT_01 | CAP_BYP_CONFIG_FAULT_02 | CAP_BYP_CONFIG_FAULT_03 |                       \
    CAP_BYP_CONFIG_FAULT_04 | CAP_BYP_CONFIG_FAULT_05 | CAP_BYP_CONFIG_FAULT_06 | CAP_BYP_CONFIG_FAULT_07 |                       \
    CAP_BYP_CONFIG_FAULT_08 | CAP_BYP_CONFIG_FAULT_09 | CAP_BYP_CONFIG_FAULT_10 | CAP_BYP_CONFIG_FAULT_11 |                       \
    CAP_BYP_CONFIG_FAULT_12 | CAP_BYP_CONFIG_FAULT_13 | CAP_BYP_CONFIG_FAULT_14 | CAP_BYP_CONFIG_FAULT_15 |                       \
    CAP_BYP_CONFIG_FAULT_16 | CAP_BYP_CONFIG_FAULT_17 | CAP_BYP_CONFIG_FAULT_18 | CAP_BYP_CONFIG_FAULT_19 |                       \
    CAP_BYP_CONFIG_FAULT_20 | CAP_BYP_CONFIG_FAULT_21 | CAP_BYP_CONFIG_FAULT_22 | CAP_BYP_CONFIG_FAULT_23 |                       \
    CAP_BYP_CONFIG_FAULT_24 | CAP_BYP_CONFIG_FAULT_25 | CAP_BYP_CONFIG_FAULT_26 | CAP_BYP_CONFIG_FAULT_27 |                       \
    CAP_BYP_CONFIG_FAULT_28 | CAP_BYP_CONFIG_FAULT_29 | CAP_BYP_CONFIG_FAULT_30 | CAP_BYP_CONFIG_FAULT_31)

#define CAP_BYP_CONFIG1                                                                                                           \
   (CAP_BYP_CONFIG_FAULT_32 | CAP_BYP_CONFIG_FAULT_33 | CAP_BYP_CONFIG_FAULT_34 | CAP_BYP_CONFIG_FAULT_35 |                       \
    CAP_BYP_CONFIG_FAULT_36 | CAP_BYP_CONFIG_FAULT_37 | CAP_BYP_CONFIG_FAULT_38 | CAP_BYP_CONFIG_FAULT_39 |                       \
    CAP_BYP_CONFIG_FAULT_40 | CAP_BYP_CONFIG_FAULT_41 | CAP_BYP_CONFIG_FAULT_42 | CAP_BYP_CONFIG_FAULT_43 |                       \
    CAP_BYP_CONFIG_FAULT_44 | CAP_BYP_CONFIG_FAULT_45 | CAP_BYP_CONFIG_FAULT_46 | CAP_BYP_CONFIG_FAULT_47 |                       \
    CAP_BYP_CONFIG_FAULT_48 | CAP_BYP_CONFIG_FAULT_49 | CAP_BYP_CONFIG_FAULT_50 | CAP_BYP_CONFIG_FAULT_51 |                       \
    CAP_BYP_CONFIG_FAULT_52 | CAP_BYP_CONFIG_FAULT_53 | CAP_BYP_CONFIG_FAULT_54 | CAP_BYP_CONFIG_FAULT_55 |                       \
    CAP_BYP_CONFIG_FAULT_56 | CAP_BYP_CONFIG_FAULT_57 | CAP_BYP_CONFIG_FAULT_58 | CAP_BYP_CONFIG_FAULT_59 |                       \
    CAP_BYP_CONFIG_FAULT_60 | CAP_BYP_CONFIG_FAULT_61 | CAP_BYP_CONFIG_FAULT_62 | CAP_BYP_CONFIG_FAULT_63)

#define PMU_FAULTB_CONFIG ACTIVE_LOW_INACTIVE_HIGH

#define FCRU_RESET_REASON_OFFSET1 100U
#define FCRU_RESET_REASON_OFFSET2 132U

#define FCRU_PBL_MAJOR_VERSION 1U
#define FCRU_PBL_MINOR_VERSION 6U
#define FCRU_PBL_PATCH_VERSION 6U

/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *  Date        Name   (Description on following lines: SCR #, etc.)
 * --------     -----   ---------------------------------------------
 *
\*===========================================================================*/

#endif /* } SWC_PLT_CDD_FCRU_CFG_H */
