#ifndef FAULT_LIB_PRJ_H
#define FAULT_LIB_PRJ_H

/**\file
 *
 * Brief description of the file ends at this dot. Detailed decription
 * follows here
 *
 * \b Project:              Autosar Platform \n
 * \b Application:          Fault_Lib_Prj \n
 * \b Target:               \n
 * \b Compiler:             \n
 * \b Module:               %name:Fault_Lib_Prj.h % \n
 * \b File-Revision:        %version:    5 % \n
 * \b Changeable-by-user:   Yes \n
 * \b Module-Owner:         %owner: % \n
 * \b Last-Changed-Date:    %date_modified: Fri Oct 05:33:50 2017 % \n
 * \b Classification:       CONFIDENTIAL \n
 * \Requirements
 * \reqtrace
 */

/*====================================================================================================================*\
 *
 * Copyright (C) 2021 Aptiv. All rights reserved
 * It is not allowed to reproduce or utilize parts of this document in any form
 * or by any means, including photocopying and microfilm, without permission in
 * written by Aptiv.
 *
\*====================================================================================================================*/

/*====================================================================================================================*\
 * PREPROCESSOR DIRECTIVES
\*====================================================================================================================*/
/* INCLUDE DIRECTIVES FOR STANDARD HEADERS ---------------------------------------------------------------------------*/
#include "Fault_Lib_Plt.h"
#include "Std_Types.h"
#include "fixmac.h"
#include "reuse.h"
#include "string.h"

#ifndef boolean_T
typedef unsigned char boolean_T; /**< Boolean */
#endif

/* INCLUDE DIRECTIVES FOR OTHER HEADERS ------------------------------------------------------------------------------*/
/* Include of these files for the suport of Variants in the code */

/* EXPORTED DEFINE MACROS (#, ##) ------------------------------------------------------------------------------------*/
#define T_BIT                        ((bitfield8_t)TRUE)
#define F_BIT                        ((bitfield8_t)FALSE)
#define BYTE_SIZE                    (8U)
#define PLATFORM_FAULT_TABLE_SIZE    (16U)
#define MAX_NUMBER_OF_PLATFORM_TYPES (PLATFORM_FAULT_TABLE_SIZE * BYTE_SIZE)

/*
CODED_TRUE      0xAAu
CODED_FALSE     0x55u
*/

#define DIAG_ENABLE_FAULT  (0xAAu)
#define DIAG_DISABLE_FAULT (0x55u)

#define DIAG_TEST_NOT_COMPLETED (0U)
#define DIAG_TEST_FAIL          (85U)
#define DIAG_TEST_PASS          (170U)
/* MACROS FOR FAULT TABLE OVERRIDE XCP */
#define PLTFORM_AUTO_MODE         (1U)
#define PLATFORM_SET_FAULT_MODE   (2U)
#define PLATFORM_CLEAR_FAULT_MODE (3U)

/* CUSTOMER FAULT RELATED TABLES */
#define CUSTOMER_LATCH_ENABLE_TABLE_SET_VALUES                                                                                    \
   {                                                                                                                              \
      F_BIT, /* 0.7 */     /*reserved_0_7,                                             */                                         \
         F_BIT, /* 0.6 */  /*reserved_0_6,                                             */                                         \
         F_BIT, /* 0.5 */  /*reserved_0_5,                                             */                                         \
         F_BIT, /* 0.4 */  /*reserved_0_4,                                             */                                         \
         F_BIT, /* 0.3 */  /*reserved_0_3,                                             */                                         \
         F_BIT, /* 0.2 */  /*reserved_0_2,                                             */                                         \
         F_BIT, /* 0.1 */  /*reserved_0_1,                                             */                                         \
         F_BIT, /* 0.0 */  /*reserved_0_0,                                             */                                         \
         F_BIT, /* 1.7 */  /*reserved_1_7,                                             */                                         \
         F_BIT, /* 1.6 */  /*reserved_1_6,                                             */                                         \
         F_BIT, /* 1.5 */  /*reserved_1_5,                                             */                                         \
         F_BIT, /* 1.4 */  /*reserved_1_4,                                             */                                         \
         F_BIT, /* 1.3 */  /*reserved_1_3,                                             */                                         \
         F_BIT, /* 1.2 */  /*reserved_1_2,                                             */                                         \
         F_BIT, /* 1.1 */  /*reserved_1_1,                                             */                                         \
         F_BIT, /* 1.0 */  /*reserved_1_0,                                             */                                         \
         F_BIT, /* 2.7 */  /*reserved_2_7,                                             */                                         \
         F_BIT, /* 2.6 */  /*reserved_2_6,                                             */                                         \
         F_BIT, /* 2.5 */  /*reserved_2_5,                                             */                                         \
         F_BIT, /* 2.4 */  /*reserved_2_4,                                             */                                         \
         F_BIT, /* 2.3 */  /*reserved_2_3,                                             */                                         \
         F_BIT, /* 2.2 */  /*reserved_2_2,                                             */                                         \
         F_BIT, /* 2.1 */  /*reserved_2_1,                                             */                                         \
         F_BIT, /* 2.0 */  /*reserved_2_0,                                             */                                         \
         F_BIT, /* 3.7 */  /*reserved_3_7,                                             */                                         \
         F_BIT, /* 3.6 */  /*reserved_3_6,                                             */                                         \
         F_BIT, /* 3.5 */  /*reserved_3_5,                                             */                                         \
         F_BIT, /* 3.4 */  /*reserved_3_4,                                             */                                         \
         F_BIT, /* 3.3 */  /*reserved_3_3,                                             */                                         \
         F_BIT, /* 3.2 */  /*reserved_3_2,                                             */                                         \
         F_BIT, /* 3.1 */  /*reserved_3_1,                                             */                                         \
         F_BIT, /* 3.0 */  /*reserved_3_0,                                             */                                         \
         F_BIT, /* 4.7 */  /*reserved_4_7,                                             */                                         \
         F_BIT, /* 4.6 */  /*reserved_4_6,                                             */                                         \
         F_BIT, /* 4.5 */  /*reserved_4_5,                                             */                                         \
         F_BIT, /* 4.4 */  /*reserved_4_4,                                             */                                         \
         F_BIT, /* 4.3 */  /*reserved_4_3,                                             */                                         \
         F_BIT, /* 4.2 */  /*reserved_4_2,                                             */                                         \
         F_BIT, /* 4.1 */  /*reserved_4_1,                                             */                                         \
         F_BIT, /* 4.0 */  /*reserved_4_0,                                             */                                         \
         F_BIT, /* 5.7 */  /*reserved_5_7,                                             */                                         \
         F_BIT, /* 5.6 */  /*reserved_5_6,                                             */                                         \
         F_BIT, /* 5.5 */  /*reserved_5_5,                                             */                                         \
         F_BIT, /* 5.4 */  /*reserved_5_4,                                             */                                         \
         F_BIT, /* 5.3 */  /*reserved_5_3,                                             */                                         \
         F_BIT, /* 5.2 */  /*reserved_5_2,                                             */                                         \
         F_BIT, /* 5.1 */  /*reserved_5_1,                                             */                                         \
         F_BIT, /* 5.0 */  /*reserved_5_0,                                             */                                         \
         F_BIT, /* 6.7 */  /*reserved_6_7,                                             */                                         \
         F_BIT, /* 6.6 */  /*reserved_6_6,                                             */                                         \
         F_BIT, /* 6.5 */  /*reserved_6_5,                                             */                                         \
         F_BIT, /* 6.4 */  /*reserved_6_4,                                             */                                         \
         F_BIT, /* 6.3 */  /*reserved_6_3,                                             */                                         \
         F_BIT, /* 6.2 */  /*reserved_6_2,                                             */                                         \
         F_BIT, /* 6.1 */  /*reserved_6_1,                                             */                                         \
         F_BIT, /* 6.0 */  /*reserved_6_0,                                             */                                         \
         F_BIT, /* 7.7 */  /*reserved_7_7,                                             */                                         \
         F_BIT, /* 7.6 */  /*reserved_7_6,                                             */                                         \
         F_BIT, /* 7.5 */  /*reserved_7_5,                                             */                                         \
         F_BIT, /* 7.4 */  /*reserved_7_4,                                             */                                         \
         F_BIT, /* 7.3 */  /*reserved_7_3,                                             */                                         \
         F_BIT, /* 7.2 */  /*reserved_7_2,                                             */                                         \
         F_BIT, /* 7.1 */  /*reserved_7_1,                                             */                                         \
         F_BIT, /* 7.0 */  /*reserved_7_0,                                             */                                         \
         F_BIT, /* 8.7 */  /*reserved_8_7,                                             */                                         \
         F_BIT, /* 8.6 */  /*reserved_8_6,                                             */                                         \
         F_BIT, /* 8.5 */  /*reserved_8_5,                                             */                                         \
         F_BIT, /* 8.4 */  /*reserved_8_4,                                             */                                         \
         F_BIT, /* 8.3 */  /*reserved_8_3,                                             */                                         \
         F_BIT, /* 8.2 */  /*reserved_8_2,                                             */                                         \
         F_BIT, /* 8.1 */  /*reserved_8_1,                                             */                                         \
         F_BIT, /* 8.0 */  /*reserved_8_0,                                             */                                         \
         F_BIT, /* 9.7 */  /*reserved_9_7,                                             */                                         \
         F_BIT, /* 9.6 */  /*reserved_9_6,                                             */                                         \
         F_BIT, /* 9.5 */  /*reserved_9_5,                                             */                                         \
         F_BIT, /* 9.4 */  /*reserved_9_4,                                             */                                         \
         F_BIT, /* 9.3 */  /*reserved_9_3,                                             */                                         \
         F_BIT, /* 9.2 */  /*reserved_9_2,                                             */                                         \
         F_BIT, /* 9.1 */  /*reserved_9_1,                                             */                                         \
         F_BIT, /* 9.0 */  /*reserved_9_0,                                             */                                         \
         F_BIT, /* 10.7 */ /*reserved_10_7,                                            */                                         \
         F_BIT, /* 10.6 */ /*reserved_10_6,                                            */                                         \
         F_BIT, /* 10.5 */ /*reserved_10_5,                                            */                                         \
         F_BIT, /* 10.4 */ /*reserved_10_4,                                            */                                         \
         F_BIT, /* 10.3 */ /*reserved_10_3,                                            */                                         \
         F_BIT, /* 10.2 */ /*reserved_10_2,                                            */                                         \
         F_BIT, /* 10.1 */ /*reserved_10_1,                                            */                                         \
         F_BIT, /* 10.0 */ /*reserved_10_0,                                            */                                         \
         F_BIT, /* 11.7 */ /*reserved_11_7,                                            */                                         \
         F_BIT, /* 11.6 */ /*reserved_11_6,                                            */                                         \
         F_BIT, /* 11.5 */ /*reserved_11_5,                                            */                                         \
         F_BIT, /* 11.4 */ /*reserved_11_4,                                            */                                         \
         F_BIT, /* 11.3 */ /*reserved_11_3,                                            */                                         \
         F_BIT, /* 11.2 */ /*reserved_11_2,                                            */                                         \
         F_BIT, /* 11.1 */ /*reserved_11_1,                                            */                                         \
         F_BIT, /* 11.0 */ /*reserved_11_0,                                            */                                         \
         F_BIT, /* 12.7 */ /*reserved_12_7,                                            */                                         \
         F_BIT, /* 12.6 */ /*reserved_12_6,                                            */                                         \
         F_BIT, /* 12.5 */ /*reserved_12_5,                                            */                                         \
         F_BIT, /* 12.4 */ /*reserved_12_4,                                            */                                         \
         F_BIT, /* 12.3 */ /*reserved_12_3,                                            */                                         \
         F_BIT, /* 12.2 */ /*reserved_12_2,                                            */                                         \
         F_BIT, /* 12.1 */ /*reserved_12_1,                                            */                                         \
         F_BIT, /* 12.0 */ /*reserved_12_0,                                            */                                         \
         F_BIT, /* 13.7 */ /*reserved_13_7,                                            */                                         \
         F_BIT, /* 13.6 */ /*reserved_13_6,                                            */                                         \
         F_BIT, /* 13.5 */ /*reserved_13_5,                                            */                                         \
         F_BIT, /* 13.4 */ /*reserved_13_4,                                            */                                         \
         F_BIT, /* 13.3 */ /*reserved_13_3,                                            */                                         \
         F_BIT, /* 13.2 */ /*reserved_13_2,                                            */                                         \
         F_BIT, /* 13.1 */ /*reserved_13_1,                                            */                                         \
         F_BIT, /* 13.0 */ /*reserved_13_0,                                            */                                         \
         F_BIT, /* 14.7 */ /*reserved_14_7,                                            */                                         \
         F_BIT, /* 14.6 */ /*reserved_14_6,                                            */                                         \
         F_BIT, /* 14.5 */ /*reserved_14_5,                                            */                                         \
         F_BIT, /* 14.4 */ /*reserved_14_4,                                            */                                         \
         F_BIT, /* 14.3 */ /*reserved_14_3,                                            */                                         \
         F_BIT, /* 14.2 */ /*reserved_14_2,                                            */                                         \
         F_BIT, /* 14.1 */ /*reserved_14_1,                                            */                                         \
         F_BIT, /* 14.0 */ /*reserved_14_0,                                            */                                         \
         F_BIT, /* 15.7 */ /*reserved_15_7,                                            */                                         \
         F_BIT, /* 15.6 */ /*reserved_15_6,                                            */                                         \
         F_BIT, /* 15.5 */ /*reserved_15_5,                                            */                                         \
         F_BIT, /* 15.4 */ /*reserved_15_4,                                            */                                         \
         F_BIT, /* 15.3 */ /*reserved_15_3,                                            */                                         \
         F_BIT, /* 15.2 */ /*reserved_15_2,                                            */                                         \
         F_BIT, /* 15.1 */ /*reserved_15_1,                                            */                                         \
         F_BIT, /* 15.0 */ /*reserved_15_0,                                            */                                         \
         F_BIT, /* 16.7 */ /*reserved_16_7,                                            */                                         \
         F_BIT, /* 16.6 */ /*reserved_16_6,                                            */                                         \
         F_BIT, /* 16.5 */ /*reserved_16_5,                                            */                                         \
         F_BIT, /* 16.4 */ /*reserved_16_4,                                            */                                         \
         F_BIT, /* 16.3 */ /*reserved_16_3,                                            */                                         \
         F_BIT, /* 16.2 */ /*Vcan_bus_off_fault,                                       */                                         \
         F_BIT, /* 16.1 */ /*pcan_bus_off_fault,                                       */                                         \
         F_BIT, /* 16.0 */ /*reserved_16_0,                                            */                                         \
         F_BIT, /* 17.7 */ /*CLS_TX_4_message_timeout_fault,                                            */                        \
         F_BIT, /* 17.6 */ /*CLS_Tx_16_message_timeout_fault,                                            */                       \
         F_BIT, /* 17.5 */ /*ADAS_Function_Switch_message_timeout_fault,                                            */            \
         F_BIT, /* 17.4 */ /*ETC2_AT_AMT_Variant_message_timeout_fault,                                            */             \
         F_BIT, /* 17.3 */ /*VDC2_message_timeout_fault,                                            */                            \
         F_BIT, /* 17.2 */ /*ETC2_MT_Variant_message_timeout_fault,                                            */                 \
         F_BIT, /* 17.1 */ /*CCVS1_message_timeout_fault,                                            */                           \
         F_BIT, /* 17.0 */ /*reserved_17_0,                                            */                                         \
         F_BIT, /* 18.7 */ /*reserved_18_7,                                            */                                         \
         F_BIT, /* 18.6 */ /*reserved_18_6,                                            */                                         \
         F_BIT, /* 18.5 */ /*reserved_18_5,                                            */                                         \
         F_BIT, /* 18.4 */ /*reserved_18_4,                                            */                                         \
         F_BIT, /* 18.3 */ /*SAS_message_timeout_fault,                                            */                             \
         F_BIT, /* 18.2 */ /*VD_message_timeout_fault,                                            */                              \
         F_BIT, /* 18.1 */ /*TD_message_timeout_fault,                                            */                              \
         F_BIT, /* 18.0 */ /*OEL_message_timeout_fault,                                            */                             \
         F_BIT, /* 19.7 */ /*PCAN_Message_timeout_fault,                                            */                            \
         F_BIT, /* 19.6 */ /*reserved_19_6,                                            */                                         \
         F_BIT, /* 19.5 */ /*reserved_19_5,                                            */                                         \
         F_BIT, /* 19.4 */ /*reserved_19_4,                                            */                                         \
         F_BIT, /* 19.3 */ /*reserved_19_3,                                            */                                         \
         F_BIT, /* 19.2 */ /*reserved_19_2,                                            */                                         \
         F_BIT, /* 19.1 */ /*reserved_19_1,                                            */                                         \
         F_BIT, /* 19.0 */ /*reserved_19_0,                                            */                                         \
         F_BIT, /* 20.7 */ /*reserved_20_7,                                            */                                         \
         F_BIT, /* 20.6 */ /*reserved_20_6,                                            */                                         \
         F_BIT, /* 20.5 */ /*reserved_20_5,                                            */                                         \
         F_BIT, /* 20.4 */ /*reserved_20_4,                                            */                                         \
         F_BIT, /* 20.3 */ /*reserved_20_3,                                            */                                         \
         F_BIT, /* 20.2 */ /*reserved_20_2,                                            */                                         \
         F_BIT, /* 20.1 */ /*reserved_20_1,                                            */                                         \
         F_BIT, /* 20.0 */ /*reserved_20_0,                                            */                                         \
         F_BIT, /* 21.7 */ /*Prj_Battery_High_fault,                                            */                                \
         F_BIT, /* 21.6 */ /*Prj_Battery_Low_fault,                                            */                                 \
         F_BIT, /* 21.5 */ /*reserved_21_5,                                            */                                         \
         F_BIT, /* 21.4 */ /*reserved_21_4,                                            */                                         \
         F_BIT, /* 21.3 */ /*reserved_21_3,                                            */                                         \
         F_BIT, /* 21.2 */ /*reserved_22_2,                                            */                                         \
         F_BIT, /* 21.1 */ /*reserved_21_1,                                            */                                         \
         F_BIT, /* 21.0 */ /*reserved_21_0,                                            */                                         \
   }

#define CUSTOMER_FAULT_ENABLE_TABLE_VALUES                                                                                        \
   {                                                                                                                              \
      F_BIT, /* 0.7 */     /*reserved_0_7,                                             */                                         \
         F_BIT, /* 0.6 */  /*reserved_0_6,                                             */                                         \
         F_BIT, /* 0.5 */  /*reserved_0_5,                                             */                                         \
         F_BIT, /* 0.4 */  /*reserved_0_4,                                             */                                         \
         F_BIT, /* 0.3 */  /*reserved_0_3,                                             */                                         \
         F_BIT, /* 0.2 */  /*reserved_0_2,                                             */                                         \
         F_BIT, /* 0.1 */  /*reserved_0_1,                                             */                                         \
         F_BIT, /* 0.0 */  /*reserved_0_0,                                             */                                         \
         F_BIT, /* 1.7 */  /*reserved_1_7,                                             */                                         \
         F_BIT, /* 1.6 */  /*reserved_1_6,                                             */                                         \
         F_BIT, /* 1.5 */  /*reserved_1_5,                                             */                                         \
         F_BIT, /* 1.4 */  /*reserved_1_4,                                             */                                         \
         F_BIT, /* 1.3 */  /*reserved_1_3,                                             */                                         \
         F_BIT, /* 1.2 */  /*reserved_1_2,                                             */                                         \
         F_BIT, /* 1.1 */  /*reserved_1_1,                                             */                                         \
         F_BIT, /* 1.0 */  /*reserved_1_0,                                             */                                         \
         F_BIT, /* 2.7 */  /*reserved_2_7,                                             */                                         \
         F_BIT, /* 2.6 */  /*reserved_2_6,                                             */                                         \
         F_BIT, /* 2.5 */  /*reserved_2_5,                                             */                                         \
         F_BIT, /* 2.4 */  /*reserved_2_4,                                             */                                         \
         F_BIT, /* 2.3 */  /*reserved_2_3,                                             */                                         \
         F_BIT, /* 2.2 */  /*reserved_2_2,                                             */                                         \
         F_BIT, /* 2.1 */  /*reserved_2_1,                                             */                                         \
         F_BIT, /* 2.0 */  /*reserved_2_0,                                             */                                         \
         F_BIT, /* 3.7 */  /*reserved_3_7,                                             */                                         \
         F_BIT, /* 3.6 */  /*reserved_3_6,                                             */                                         \
         F_BIT, /* 3.5 */  /*reserved_3_5,                                             */                                         \
         F_BIT, /* 3.4 */  /*reserved_3_4,                                             */                                         \
         F_BIT, /* 3.3 */  /*reserved_3_3,                                             */                                         \
         F_BIT, /* 3.2 */  /*reserved_3_2,                                             */                                         \
         F_BIT, /* 3.1 */  /*reserved_3_1,                                             */                                         \
         F_BIT, /* 3.0 */  /*reserved_3_0,                                             */                                         \
         F_BIT, /* 4.7 */  /*reserved_4_7,                                             */                                         \
         F_BIT, /* 4.6 */  /*reserved_4_6,                                             */                                         \
         F_BIT, /* 4.5 */  /*reserved_4_5,                                             */                                         \
         F_BIT, /* 4.4 */  /*reserved_4_4,                                             */                                         \
         F_BIT, /* 4.3 */  /*reserved_4_3,                                             */                                         \
         F_BIT, /* 4.2 */  /*reserved_4_2,                                             */                                         \
         F_BIT, /* 4.1 */  /*reserved_4_1,                                             */                                         \
         F_BIT, /* 4.0 */  /*reserved_4_0,                                             */                                         \
         F_BIT, /* 5.7 */  /*reserved_5_7,                                             */                                         \
         F_BIT, /* 5.6 */  /*reserved_5_6,                                             */                                         \
         F_BIT, /* 5.5 */  /*reserved_5_5,                                             */                                         \
         F_BIT, /* 5.4 */  /*reserved_5_4,                                             */                                         \
         F_BIT, /* 5.3 */  /*reserved_5_3,                                             */                                         \
         F_BIT, /* 5.2 */  /*reserved_5_2,                                             */                                         \
         F_BIT, /* 5.1 */  /*reserved_5_1,                                             */                                         \
         F_BIT, /* 5.0 */  /*reserved_5_0,                                             */                                         \
         F_BIT, /* 6.7 */  /*reserved_6_7,                                             */                                         \
         F_BIT, /* 6.6 */  /*reserved_6_6,                                             */                                         \
         F_BIT, /* 6.5 */  /*reserved_6_5,                                             */                                         \
         F_BIT, /* 6.4 */  /*reserved_6_4,                                             */                                         \
         F_BIT, /* 6.3 */  /*reserved_6_3,                                             */                                         \
         F_BIT, /* 6.2 */  /*reserved_6_2,                                             */                                         \
         F_BIT, /* 6.1 */  /*reserved_6_1,                                             */                                         \
         F_BIT, /* 6.0 */  /*reserved_6_0,                                             */                                         \
         F_BIT, /* 7.7 */  /*reserved_7_7,                                             */                                         \
         F_BIT, /* 7.6 */  /*reserved_7_6,                                             */                                         \
         F_BIT, /* 7.5 */  /*reserved_7_5,                                             */                                         \
         F_BIT, /* 7.4 */  /*reserved_7_4,                                             */                                         \
         F_BIT, /* 7.3 */  /*reserved_7_3,                                             */                                         \
         F_BIT, /* 7.2 */  /*reserved_7_2,                                             */                                         \
         F_BIT, /* 7.1 */  /*reserved_7_1,                                             */                                         \
         F_BIT, /* 7.0 */  /*reserved_7_0,                                             */                                         \
         F_BIT, /* 8.7 */  /*reserved_8_7,                                             */                                         \
         F_BIT, /* 8.6 */  /*reserved_8_6,                                             */                                         \
         F_BIT, /* 8.5 */  /*reserved_8_5,                                             */                                         \
         F_BIT, /* 8.4 */  /*reserved_8_4,                                             */                                         \
         F_BIT, /* 8.3 */  /*reserved_8_3,                                             */                                         \
         F_BIT, /* 8.2 */  /*reserved_8_2,                                             */                                         \
         F_BIT, /* 8.1 */  /*reserved_8_1,                                             */                                         \
         F_BIT, /* 8.0 */  /*reserved_8_0,                                             */                                         \
         F_BIT, /* 9.7 */  /*reserved_9_7,                                             */                                         \
         F_BIT, /* 9.6 */  /*reserved_9_6,                                             */                                         \
         F_BIT, /* 9.5 */  /*reserved_9_5,                                             */                                         \
         F_BIT, /* 9.4 */  /*reserved_9_4,                                             */                                         \
         F_BIT, /* 9.3 */  /*reserved_9_3,                                             */                                         \
         F_BIT, /* 9.2 */  /*reserved_9_2,                                             */                                         \
         F_BIT, /* 9.1 */  /*reserved_9_1,                                             */                                         \
         F_BIT, /* 9.0 */  /*reserved_9_0,                                             */                                         \
         F_BIT, /* 10.7 */ /*reserved_10_7,                                            */                                         \
         F_BIT, /* 10.6 */ /*reserved_10_6,                                            */                                         \
         F_BIT, /* 10.5 */ /*reserved_10_5,                                            */                                         \
         F_BIT, /* 10.4 */ /*reserved_10_4,                                            */                                         \
         F_BIT, /* 10.3 */ /*reserved_10_3,                                            */                                         \
         F_BIT, /* 10.2 */ /*reserved_10_2,                                            */                                         \
         F_BIT, /* 10.1 */ /*reserved_10_1,                                            */                                         \
         F_BIT, /* 10.0 */ /*reserved_10_0,                                            */                                         \
         F_BIT, /* 11.7 */ /*reserved_11_7,                                            */                                         \
         F_BIT, /* 11.6 */ /*reserved_11_6,                                            */                                         \
         F_BIT, /* 11.5 */ /*reserved_11_5,                                            */                                         \
         F_BIT, /* 11.4 */ /*reserved_11_4,                                            */                                         \
         F_BIT, /* 11.3 */ /*reserved_11_3,                                            */                                         \
         F_BIT, /* 11.2 */ /*reserved_11_2,                                            */                                         \
         F_BIT, /* 11.1 */ /*reserved_11_1,                                            */                                         \
         F_BIT, /* 11.0 */ /*reserved_11_0,                                            */                                         \
         F_BIT, /* 12.7 */ /*reserved_12_7,                                            */                                         \
         F_BIT, /* 12.6 */ /*reserved_12_6,                                            */                                         \
         F_BIT, /* 12.5 */ /*reserved_12_5,                                            */                                         \
         F_BIT, /* 12.4 */ /*reserved_12_4,                                            */                                         \
         F_BIT, /* 12.3 */ /*reserved_12_3,                                            */                                         \
         F_BIT, /* 12.2 */ /*reserved_12_2,                                            */                                         \
         F_BIT, /* 12.1 */ /*reserved_12_1,                                            */                                         \
         F_BIT, /* 12.0 */ /*reserved_12_0,                                            */                                         \
         F_BIT, /* 13.7 */ /*reserved_13_7,                                            */                                         \
         F_BIT, /* 13.6 */ /*reserved_13_6,                                            */                                         \
         F_BIT, /* 13.5 */ /*reserved_13_5,                                            */                                         \
         F_BIT, /* 13.4 */ /*reserved_13_4,                                            */                                         \
         F_BIT, /* 13.3 */ /*reserved_13_3,                                            */                                         \
         F_BIT, /* 13.2 */ /*reserved_13_2,                                            */                                         \
         F_BIT, /* 13.1 */ /*reserved_13_1,                                            */                                         \
         F_BIT, /* 13.0 */ /*reserved_13_0,                                            */                                         \
         F_BIT, /* 14.7 */ /*reserved_14_7,                                            */                                         \
         F_BIT, /* 14.6 */ /*reserved_14_6,                                            */                                         \
         F_BIT, /* 14.5 */ /*reserved_14_5,                                            */                                         \
         F_BIT, /* 14.4 */ /*reserved_14_4,                                            */                                         \
         F_BIT, /* 14.3 */ /*reserved_14_3,                                            */                                         \
         F_BIT, /* 14.2 */ /*reserved_14_2,                                            */                                         \
         F_BIT, /* 14.1 */ /*reserved_14_1,                                            */                                         \
         F_BIT, /* 14.0 */ /*reserved_14_0,                                            */                                         \
         F_BIT, /* 15.7 */ /*reserved_15_7,                                            */                                         \
         F_BIT, /* 15.6 */ /*reserved_15_6,                                            */                                         \
         F_BIT, /* 15.5 */ /*reserved_15_5,                                            */                                         \
         F_BIT, /* 15.4 */ /*reserved_15_4,                                            */                                         \
         F_BIT, /* 15.3 */ /*reserved_15_3,                                            */                                         \
         F_BIT, /* 15.2 */ /*reserved_15_2,                                            */                                         \
         F_BIT, /* 15.1 */ /*reserved_15_1,                                            */                                         \
         F_BIT, /* 15.0 */ /*reserved_15_0,                                            */                                         \
         F_BIT, /* 16.7 */ /*reserved_16_7,                                            */                                         \
         F_BIT, /* 16.6 */ /*reserved_16_6,                                            */                                         \
         F_BIT, /* 16.5 */ /*reserved_16_5,                                            */                                         \
         T_BIT, /* 16.4 */ /*Time_synchronization_fault,                               */                                         \
         F_BIT, /* 16.3 */ /*reserved_16_3,                                            */                                         \
         T_BIT, /* 16.2 */ /*Vcan_bus_off_fault,                                       */                                         \
         T_BIT, /* 16.1 */ /*pcan_bus_off_fault,                                       */                                         \
         T_BIT, /* 16.0 */ /*pin_position_mismatch,                                            */                                 \
         T_BIT, /* 17.7 */ /*CLS_TX_4_message_timeout_fault,                                            */                        \
         T_BIT, /* 17.6 */ /*CLS_Tx_16_message_timeout_fault,                                            */                       \
         T_BIT, /* 17.5 */ /*ADAS_Function_Switch_message_timeout_fault,                                            */            \
         T_BIT, /* 17.4 */ /*ETC2_AT_AMT_Variant_message_timeout_fault,                                            */             \
         T_BIT, /* 17.3 */ /*VDC2_message_timeout_fault,                                            */                            \
         T_BIT, /* 17.2 */ /*ETC2_MT_Variant_message_timeout_fault,                                            */                 \
         T_BIT, /* 17.1 */ /*CCVS1_message_timeout_fault,                                            */                           \
         F_BIT, /* 17.0 */ /*reserved_17_0,                                            */                                         \
         F_BIT, /* 18.7 */ /*reserved_18_7,                                            */                                         \
         F_BIT, /* 18.6 */ /*reserved_18_6,                                            */                                         \
         F_BIT, /* 18.5 */ /*reserved_18_5,                                            */                                         \
         F_BIT, /* 18.4 */ /*reserved_18_4,                                            */                                         \
         T_BIT, /* 18.3 */ /*SAS_message_timeout_fault,                                            */                             \
         T_BIT, /* 18.2 */ /*VD_message_timeout_fault,                                            */                              \
         T_BIT, /* 18.1 */ /*TD_message_timeout_fault,                                            */                              \
         T_BIT, /* 18.0 */ /*OEL_message_timeout_fault,                                            */                             \
         T_BIT, /* 19.7 */ /*PCAN_Message_timeout_fault ,                                            */                           \
         F_BIT, /* 19.6 */ /*reserved_19_6,                                            */                                         \
         F_BIT, /* 19.5 */ /*reserved_19_5,                                            */                                         \
         F_BIT, /* 19.4 */ /*reserved_19_4,                                            */                                         \
         F_BIT, /* 19.3 */ /*reserved_19_3,                                            */                                         \
         F_BIT, /* 19.2 */ /*reserved_19_2,                                            */                                         \
         F_BIT, /* 19.1 */ /*reserved_19_1,                                            */                                         \
         F_BIT, /* 19.0 */ /*reserved_19_0,                                            */                                         \
         F_BIT, /* 20.7 */ /*reserved_20_7,                                            */                                         \
         F_BIT, /* 20.6 */ /*reserved_20_6,                                            */                                         \
         F_BIT, /* 20.5 */ /*reserved_20_5,                                            */                                         \
         F_BIT, /* 20.4 */ /*reserved_20_4,                                            */                                         \
         F_BIT, /* 20.3 */ /*reserved_20_3,                                            */                                         \
         F_BIT, /* 20.2 */ /*reserved_20_2,                                            */                                         \
         F_BIT, /* 20.1 */ /*reserved_20_1,                                            */                                         \
         F_BIT, /* 20.0 */ /*reserved_20_0,                                            */                                         \
         T_BIT, /* 21.7 */ /*Prj_Battery_High_fault,                                            */                                \
         T_BIT, /* 21.6 */ /*Prj_Battery_Low_fault,                                            */                                 \
         F_BIT, /* 21.5 */ /*reserved_21_5,                                            */                                         \
         F_BIT, /* 21.4 */ /*dataset_unprogrammed_fault,                                            */                            \
         F_BIT, /* 21.3 */ /*dataset_crc_failure_fault,                                            */                             \
         F_BIT, /* 21.2 */ /*reserved_21_2,                                            */                                         \
         F_BIT, /* 21.1 */ /*reserved_21_1,                                            */                                         \
         F_BIT, /* 21.0 */ /*reserved_21_0,                                            */                                         \
   }

/* packed_Customer_Fault_bits_T */
typedef struct
{
   /* 0.7 */
   bitfield8_t usc_validation_fault:1; /* lsb */
   bitfield8_t smc_validtn_fault:1;
   bitfield8_t reserved_0_5:1;
   bitfield8_t reserved_0_4:1;
   bitfield8_t mmic_transmitter_id_fault:1;
   bitfield8_t reserved_0_2:1;
   bitfield8_t core_self_test_fault:1;
   bitfield8_t reserved_0_0:1; /*msb*/
                               /* 1.7 */
   bitfield8_t reserved_1_7:1;
   bitfield8_t reserved_1_6:1;
   bitfield8_t reserved_1_5:1;
   bitfield8_t reserved_1_4:1;
   bitfield8_t reserved_1_3:1;
   bitfield8_t reserved_1_2:1;
   bitfield8_t reserved_1_1:1;
   bitfield8_t reserved_1_0:1;
   /* 2.7 */
   bitfield8_t mcu_startup_fault:1;
   bitfield8_t platform_time_fault:1;
   bitfield8_t reserved_2_5:1;
   bitfield8_t reserved_2_4:1;
   bitfield8_t reserved_2_3:1;
   bitfield8_t external_watchdog_fault:1;
   bitfield8_t mcu_repetitive_reset_fault:1;
   bitfield8_t pmic_mcu_communication_fault:1;
   /* 3.7 */
   bitfield8_t reserved_3_7:1;
   bitfield8_t reserved_3_6:1;
   bitfield8_t reserved_3_5:1;
   bitfield8_t reserved_3_4:1;
   bitfield8_t reserved_3_3:1;
   bitfield8_t reserved_3_2:1;
   bitfield8_t reserved_3_1:1;
   bitfield8_t reserved_3_0:1;
   /* 4.7 */
   bitfield8_t reserved_4_7:1;
   bitfield8_t reserved_4_6:1;
   bitfield8_t reserved_4_5:1;
   bitfield8_t reserved_4_4:1;
   bitfield8_t reserved_4_3:1;
   bitfield8_t reserved_4_2:1;
   bitfield8_t reserved_4_1:1;
   bitfield8_t reserved_4_0:1;
   /* 5.7 */
   bitfield8_t bbe_to_r52_ipc_fault:1;
   bitfield8_t r52_to_bbe_ipc_fault:1;
   bitfield8_t reserved_5_5:1;
   bitfield8_t reserved_5_4:1;
   bitfield8_t reserved_5_3:1;
   bitfield8_t reserved_5_2:1;
   bitfield8_t reserved_5_1:1;
   bitfield8_t reserved_5_0:1;
   /* 6.7 */
   bitfield8_t reserved_6_7:1;
   bitfield8_t reserved_6_6:1;
   bitfield8_t reserved_6_5:1;
   bitfield8_t reserved_6_4:1;
   bitfield8_t reserved_6_3:1;
   bitfield8_t reserved_6_2:1;
   bitfield8_t reserved_6_1:1;
   bitfield8_t reserved_6_0:1;
   /* 7.7 */
   bitfield8_t reserved_7_7:1;
   bitfield8_t reserved_7_6:1;
   bitfield8_t battery_low_fault:1;
   bitfield8_t battery_high_fault:1;
   bitfield8_t reserved_7_3:1;
   bitfield8_t reserved_7_2:1;
   bitfield8_t reserved_7_1:1;
   bitfield8_t mmic_temperature_high_fault:1;
   /* 8.7 */
   bitfield8_t reserved_8_7:1;
   bitfield8_t mmic_a_sensor_dead_fault:1;
   bitfield8_t reserved_8_5:1;
   bitfield8_t mmic_safe_start_fault:1;
   bitfield8_t api_look_config_fault:1;
   bitfield8_t api_look_trigger_fault:1;
   bitfield8_t api_look_complete_fault:1;
   bitfield8_t mmic_temperature_low_fault:1;
   /* 9.7 */
   bitfield8_t detection_processing_loop_overrun_fault:1;
   bitfield8_t mmic_repetitive_reset_fault:1;
   bitfield8_t acquisition_overflow_fault:1;
   bitfield8_t safety_integrity_fault:1;
   bitfield8_t dsp_internal_fault:1;
   bitfield8_t reserved_9_2:1;
   bitfield8_t mmic_secondary_ballbreak_fault:1;
   bitfield8_t reserved_9_0:1;
   /* 10.7 */
   bitfield8_t reserved_10_7:1;
   bitfield8_t signal_integrity_fault:1;
   bitfield8_t reserved_10_5:1;
   bitfield8_t reserved_10_4:1;
   bitfield8_t mmic_secondary_mipi_fault:1;
   bitfield8_t mmic_secondary_clock_fault:1;
   bitfield8_t mmic_secondary_register_fault:1;
   bitfield8_t detection_data_integrity_fault:1;
   /* 11.7 */
   bitfield8_t reserved_11_7:1;
   bitfield8_t rfe_tx_rfbist_err:1;
   bitfield8_t rfe_rx_rfbist_err:1;
   bitfield8_t rfe_under_over_voltage_fault:1;
   bitfield8_t mmic_secondary_mcu_fault:1;
   bitfield8_t reserved_11_2:1;
   bitfield8_t reserved_11_1:1;
   bitfield8_t reserved_11_0:1;
   /* 12.7 */
   bitfield8_t reserved_12_7:1;
   bitfield8_t reserved_12_6:1;
   bitfield8_t reserved_12_5:1;
   bitfield8_t reserved_12_4:1;
   bitfield8_t autoalignment_critical_misalignment_fault:1;
   bitfield8_t alignment_autoalignment_sudden_jump_detection_fault:1;
   bitfield8_t reserved_12_1:1;
   bitfield8_t first_pass_detection_overflow_fault:1;
   /* 13.7 */
   bitfield8_t reserved_13_7:1;
   bitfield8_t alignment_no_initial_calibration_error_fault:1;
   bitfield8_t alignment_static_calibration_error_fault:1;
   bitfield8_t alignment_service_calibration_error_fault:1;
   bitfield8_t alignment_shorttrack_calibration_error_fault:1;
   bitfield8_t alignment_autoalignment_out_of_range_fault:1;
   bitfield8_t alignment_autoalignment_algo_error_fault:1;
   bitfield8_t reserved_13_0:1;
   /* 14.7 */
   bitfield8_t reserved_14_7:1;
   bitfield8_t sll_monitoring_algo_error:1;
   bitfield8_t reserved_14_5:1;
   bitfield8_t blockage_algo_error_fault:1;
   bitfield8_t reserved_14_3:1;
   bitfield8_t reserved_14_2:1;
   bitfield8_t reserved_14_1:1;
   bitfield8_t reserved_14_0:1;
   /* 15.7 */
   bitfield8_t damping_algo_error_fault:1;
   bitfield8_t reserved_15_6:1;
   bitfield8_t range_algo_error_fault:1;
   bitfield8_t reserved_15_4:1;
   bitfield8_t reserved_15_3:1;
   bitfield8_t reserved_15_2:1;
   bitfield8_t reserved_15_1:1;
   bitfield8_t reserved_15_0:1;

   /* 16.0 */ /* Customer fault start here */
   bitfield8_t reserved_16_7:1;
   bitfield8_t reserved_16_6:1;
   bitfield8_t reserved_16_5:1;
   bitfield8_t Time_Synchronization_fault:1;
   bitfield8_t reserved_16_3:1;
   bitfield8_t vcan_bus_off_fault:1;
   bitfield8_t pcan_bus_off_fault:1;
   bitfield8_t pin_position_fault:1;
   /* 17.0 */
   bitfield8_t CLS_TX_4_message_timeout_fault:1;
   bitfield8_t CLS_Tx_16_message_timeout_fault:1;
   bitfield8_t ADAS_Function_Switch_message_timeout_fault:1;
   bitfield8_t ETC2_AT_AMT_Variant_message_timeout_fault:1;
   bitfield8_t VDC2_message_timeout_fault:1;
   bitfield8_t ETC2_MT_Variant_message_timeout_fault:1;
   bitfield8_t CCVS1_message_timeout_fault:1;
   bitfield8_t reserved_17_0:1;
   /* 18.0 */
   bitfield8_t reserved_18_7:1;
   bitfield8_t reserved_18_6:1;
   bitfield8_t reserved_18_5:1;
   bitfield8_t reserved_18_4:1;
   bitfield8_t SAS_message_timeout_fault:1;
   bitfield8_t VD_message_timeout_fault:1;
   bitfield8_t TD_message_timeout_fault:1;
   bitfield8_t OEL_message_timeout_fault:1;
   /* 19.0 */
   bitfield8_t PCAN_Message_timeout_fault:1;
   bitfield8_t reserved_19_6:1;
   bitfield8_t reserved_19_5:1;
   bitfield8_t reserved_19_4:1;
   bitfield8_t reserved_19_3:1;
   bitfield8_t reserved_19_2:1;
   bitfield8_t reserved_19_1:1;
   bitfield8_t reserved_19_0:1;
   /* 20.0 */
   bitfield8_t reserved_20_7:1;
   bitfield8_t reserved_20_6:1;
   bitfield8_t reserved_20_5:1;
   bitfield8_t reserved_20_4:1;
   bitfield8_t reserved_20_3:1;
   bitfield8_t reserved_20_2:1;
   bitfield8_t reserved_20_1:1;
   bitfield8_t reserved_20_0:1;
   /* 21.0 */
   bitfield8_t Prj_Battery_High_fault:1;
   bitfield8_t Prj_Battery_Low_fault:1;
   bitfield8_t reserved_21_5:1;
   bitfield8_t dataset_unprogrammed_fault:1;
   bitfield8_t dataset_crc_failure_fault:1;
   bitfield8_t reserved_21_2:1;
   bitfield8_t reserved_21_1:1;
   bitfield8_t reserved_21_0:1;

} packed_Customer_Fault_bits_T;

typedef enum Project_Debounce_Tag
{
   /* 0 */
   PCAN_MESSAGE_TIMEOUT_COUNT,
   CCVS1_MESSAGE_TIMEOUT_COUNT,
   VDC2_MESSAGE_TIMEOUT_COUNT,
   ETC2_MT_VARIANT_MESSAGE_TIMEOUT_COUNT,
   ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_COUNT,
   PIN_POSITION_MISMATCH_COUNT,

   /* 5 */
   ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_COUNT,
   CLS_TX_16_MESSAGE_TIMEOUT_COUNT,
   CLS_TX_4_MESSAGE_TIMEOUT_COUNT,
   OEL_MESSAGE_TIMEOUT_COUNT,
   TD_MESSAGE_TIMEOUT_COUNT,

   /*10*/
   VD_MESSAGE_TIMEOUT_COUNT,
   SAS_MESSAGE_TIMEOUT_COUNT,
   PCAN_BUSOFF_FAULT_COUNT,
   VCAN_BUSOFF_FAULT_COUNT,
   PRJ_BATTERY_HIGH_FAULT_COUNT,

   /*15*/
   /* Customer faults */
   PRJ_BATTERY_LOW_FAULT_COUNT,
   TIME_SYNCHRONIZATION_COUNT,

   /*59*/
   MAX_NUMBER_OF_PRJ_DEBOUNCE_COUNT

} Project_Debounce_Index_T;

/* Fault_Name_T */
typedef enum Prj_Fault_Name_Tag
{
   /* 0.0 */
   PRJ_RESERVED_0_0,
   PRJ_RESERVED_0_1,
   PRJ_RESERVED_0_2,
   PRJ_RESERVED_0_3,
   PRJ_RESERVED_0_4,
   PRJ_RESERVED_0_5,
   PRJ_RESERVED_0_6,
   PRJ_RESERVED_0_7,

   /* 1.0 */
   PRJ_RESERVED_1_0,
   PRJ_RESERVED_1_1,
   PRJ_RESERVED_1_2,
   PRJ_RESERVED_1_3,
   PRJ_RESERVED_1_4,
   PRJ_RESERVED_1_5,
   PRJ_RESERVED_1_6,
   PRJ_RESERVED_1_7,

   /* 2.0 */
   PRJ_RESERVED_2_0,
   PRJ_RESERVED_2_1,
   PRJ_RESERVED_2_2,
   PRJ_RESERVED_2_3,
   PRJ_RESERVED_2_4,
   PRJ_RESERVED_2_5,
   PRJ_RESERVED_2_6,
   PRJ_RESERVED_2_7,

   /* 3.0 */
   PRJ_RESERVED_3_0,
   PRJ_RESERVED_3_1,
   PRJ_RESERVED_3_2,
   PRJ_RESERVED_3_3,
   PRJ_RESERVED_3_4,
   PRJ_RESERVED_3_5,
   PRJ_RESERVED_3_6,
   PRJ_RESERVED_3_7,

   /* 4.0 */
   PRJ_RESERVED_4_0,
   PRJ_RESERVED_4_1,
   PRJ_RESERVED_4_2,
   PRJ_RESERVED_4_3,
   PRJ_RESERVED_4_4,
   PRJ_RESERVED_4_5,
   PRJ_RESERVED_4_6,
   PRJ_RESERVED_4_7,

   /* 5.0 */
   PRJ_RESERVED_5_0,
   PRJ_RESERVED_5_1,
   PRJ_RESERVED_5_2,
   PRJ_RESERVED_5_3,
   PRJ_RESERVED_5_4,
   PRJ_RESERVED_5_5,
   PRJ_RESERVED_5_6,
   PRJ_RESERVED_5_7,

   /* 6.0 */
   PRJ_RESERVED_6_0,
   PRJ_RESERVED_6_1,
   PRJ_RESERVED_6_2,
   PRJ_RESERVED_6_3,
   PRJ_RESERVED_6_4,
   PRJ_RESERVED_6_5,
   PRJ_RESERVED_6_6,
   PRJ_RESERVED_6_7,

   /* 7.0 */
   PRJ_RESERVED_7_0,
   PRJ_RESERVED_7_1,
   PRJ_RESERVED_7_2,
   PRJ_RESERVED_7_3,
   PRJ_RESERVED_7_4,
   PRJ_RESERVED_7_5,
   PRJ_RESERVED_7_6,
   PRJ_RESERVED_7_7,

   /* 8.0 */
   PRJ_RESERVED_8_0,
   PRJ_RESERVED_8_1,
   PRJ_RESERVED_8_2,
   PRJ_RESERVED_8_3,
   PRJ_RESERVED_8_4,
   PRJ_RESERVED_8_5,
   PRJ_RESERVED_8_6,
   PRJ_RESERVED_8_7,

   /* 9.0 */
   PRJ_RESERVED_9_0,
   PRJ_RESERVED_9_1,
   PRJ_RESERVED_9_2,
   PRJ_RESERVED_9_3,
   PRJ_RESERVED_9_4,
   PRJ_RESERVED_9_5,
   PRJ_RESERVED_9_6,
   PRJ_RESERVED_9_7,

   /* 10.0 */
   PRJ_RESERVED_10_0,
   PRJ_RESERVED_10_1,
   PRJ_RESERVED_10_2,
   PRJ_RESERVED_10_3,
   PRJ_RESERVED_10_4,
   PRJ_RESERVED_10_5,
   PRJ_RESERVED_10_6,
   PRJ_RESERVED_10_7,

   /* 11.0 */
   PRJ_RESERVED_11_0,
   PRJ_RESERVED_11_1,
   PRJ_RESERVED_11_2,
   PRJ_RESERVED_11_3,
   PRJ_RESERVED_11_4,
   PRJ_RESERVED_11_5,
   PRJ_RESERVED_11_6,
   PRJ_RESERVED_11_7,

   /*12.0*/
   PRJ_RESERVED_12_0,
   PRJ_RESERVED_12_1,
   PRJ_RESERVED_12_2,
   PRJ_RESERVED_12_3,
   PRJ_RESERVED_12_4,
   PRJ_RESERVED_12_5,
   PRJ_RESERVED_12_6,
   PRJ_RESERVED_12_7,

   /*13.0*/
   PRJ_RESERVED_13_0,
   PRJ_RESERVED_13_1,
   PRJ_RESERVED_13_2,
   PRJ_RESERVED_13_3,
   PRJ_RESERVED_13_4,
   PRJ_RESERVED_13_5,
   PRJ_RESERVED_13_6,
   PRJ_RESERVED_13_7,

   /*14.0*/
   PRJ_RESERVED_14_0,
   PRJ_RESERVED_14_1,
   PRJ_RESERVED_14_2,
   PRJ_RESERVED_14_3,
   PRJ_RESERVED_14_4,
   PRJ_RESERVED_14_5,
   PRJ_RESERVED_14_6,
   PRJ_RESERVED_14_7,

   /*15.0*/
   PRJ_RESERVED_15_0,
   PRJ_RESERVED_15_1,
   PRJ_RESERVED_15_2,
   PRJ_RESERVED_15_3,
   PRJ_RESERVED_15_4,
   PRJ_RESERVED_15_5,
   PRJ_RESERVED_15_6,
   PRJ_RESERVED_15_7,

   /*Platform fault end here and customer fault start here*/

   /*16.0*/
   PIN_POSITION_FAULT,
   PCAN_BUSOFF_FAULT,
   VCAN_BUSOFF_FAULT,
   PRJ_RESERVED_16_3,
   TIME_SYNCHRONIZATION_FAULT,
   PRJ_RESERVED_16_5,
   PRJ_RESERVED_16_6,
   PRJ_RESERVED_16_7,

   /*17.0*/
   PRJ_RESERVED_17_0,
   CCVS1_MESSAGE_TIMEOUT_FAULT,
   ETC2_MT_VARIANT_MESSAGE_TIMEOUT_FAULT,
   VDC2_MESSAGE_TIMEOUT_FAULT,
   ETC2_AT_AMT_VARIANT_MESSAGE_TIMEOUT_FAULT,
   ADAS_FUNCTION_SWITCH_MESSAGE_TIMEOUT_FAULT,
   CLS_TX_16_MESSAGE_TIMEOUT_FAULT,
   CLS_TX_4_MESSAGE_TIMEOUT_FAULT,

   /*18.0*/
   OEL_MESSAGE_TIMEOUT_FAULT,
   TD_MESSAGE_TIMEOUT_FAULT,
   VD_MESSAGE_TIMEOUT_FAULT,
   SAS_MESSAGE_TIMEOUT_FAULT,
   PRJ_RESERVED_18_4,
   PRJ_RESERVED_18_5,
   PRJ_RESERVED_18_6,
   PRJ_RESERVED_18_7,

   /*19.0*/
   PRJ_RESERVED_19_0,
   PRJ_RESERVED_19_1,
   PRJ_RESERVED_19_2,
   PRJ_RESERVED_19_3,
   PRJ_RESERVED_19_4,
   PRJ_RESERVED_19_5,
   PRJ_RESERVED_19_6,
   PCAN_MESSAGE_TIMEOUT_FAULT,

   /*20.0*/
   PRJ_RESERVED_20_0,
   PRJ_RESERVED_20_1,
   PRJ_RESERVED_20_2,
   PRJ_RESERVED_20_3,
   PRJ_RESERVED_20_4,
   PRJ_RESERVED_20_5,
   PRJ_RESERVED_20_6,
   PRJ_RESERVED_20_7,

   /*21.0*/
   PRJ_RESERVED_21_0,
   PRJ_RESERVED_21_1,
   PRJ_RESERVED_21_2,
   PRJ_DATASET_CRC_FAILURE_FAULT,
   PRJ_DATASET_UNPROGRAMMED_FAULT,
   PRJ_RESERVED_21_5,
   PRJ_BATTERY_LOW_FAULT,
   PRJ_BATTERY_HIGH_FAULT,

   MAX_NUMBER_OF_PRJ_FAULT_TYPES /* equals number of faults */
} Prj_Fault_Name_T;

/*====================================================================================================================*\
 * EXPORTED TYPEDEF DECLARATIONS
\*====================================================================================================================*/
typedef union
{
   Packed_Platform_Fault_bits_T Platform_Bits;
   u8p0_T Platform_byte[PLATFORM_FAULT_TABLE_SIZE];
   packed_Customer_Fault_bits_T Customer_Bits;
   u8p0_T Customer_byte[MAX_NUMBER_OF_PRJ_FAULT_TYPES / BYTE_SIZE];
} Customer_fault_T;

typedef union
{
   packed_Customer_Fault_bits_T Customer_Bits;
   u8p0_T Customer_byte[MAX_NUMBER_OF_PRJ_FAULT_TYPES / BYTE_SIZE];
} Customer_fault_Latch_Enable_T;

/* Global variables for handling the PASS/FAULT Count */
extern uint16 PRJ_Fail_Count_Debounce[MAX_NUMBER_OF_PRJ_DEBOUNCE_COUNT];
extern uint16 PRJ_Pass_Count_Debounce[MAX_NUMBER_OF_PRJ_DEBOUNCE_COUNT];
/*====================================================================================================================*\
 * EXPORTED OBJECT DECLARATIONS
\*====================================================================================================================*/
extern Platform_fault_T Platform_Active_Fault_Latched_Table;
extern Platform_fault_T Platform_History_Fault_Table;
extern const Platform_fault_T Platform_Latch_Enable_Table;

extern Customer_fault_T Customer_Active_Fault_Table;
extern Customer_fault_T Customer_Active_Fault_Latched_Table;
extern Customer_fault_T Customer_History_Fault_Table;
extern Customer_fault_T Customer_Fault_Test_Completed;
extern const Customer_fault_Latch_Enable_T Customer_Latch_Enable_Table;
extern Customer_fault_Latch_Enable_T Customer_Fault_Enable_Table;

/*====================================================================================================================*\
 * EXPORTED FUNCTIONS PROTOTYPES
\*====================================================================================================================*/
extern void Platform_memory_Copy(void *destination, void *source, uint8 num);

/*====================================================================================================================*/

/* FUNCTIONS FOR HANDLING FAULT TABLE */

extern Platform_fault_T *Get_Platform_Active_Fault_Latched_Table(void);

extern Platform_fault_T *Get_Platform_Fault_Enable_Table(void);

/*====================================================================================================================*/

/* FUNCTIONS FOR HANDLING FAULT TABLE */
extern Customer_fault_T *Get_Customer_Active_Fault_Table(void);
extern Customer_fault_T *Get_Customer_Active_Fault_Latched_Table(void);
extern Customer_fault_T *Get_Customer_History_Fault_Table(void);
extern Customer_fault_T *Get_Customer_Fault_Test_Completed_Table(void);
extern Customer_fault_Latch_Enable_T *Get_Customer_Fault_Enable_Table(void);
/*====================================================================================================================*\
 * EXPORTED FUNCTION-LIKE-MACROS and INLINE FUNCTIONS
\*====================================================================================================================*/
extern void Diagnostics_Filter_Test(uint8 test_status, uint16 fault_name, uint16 fault_fail_limit, uint16 fault_pass_limit,
                                    uint16 *fail_counter_ptr, uint16 *pass_counter_ptr);

extern void Clear_Fault_If_Enabled_and_Not_Latched(uint16 fault_name);

extern void Set_Fault_If_Enabled(uint16 fault_name);

extern void Set_Test_Completed_If_Enabled(uint16 fault_name);

extern void Diag_No_Filter_Test(uint8 test_status, uint16 fault_name);

extern uint8 Customer_Get_Fault_Status(uint16 fault_name);

extern void Clear_Cust_Fault_Arrays(void);

extern void Clear_Cust_Fault_Information(uint16 fault_name);

extern bool Cust_Check_Fault_If_Enabled(Prj_Fault_Name_T fault_name);

extern bool Cust_Fault_Enabled_Disable(Prj_Fault_Name_T fault_name, uint8 enable_status);

/* TODO: Remove after Rte_Read_SWC_PLT_CDD_Logging_Rp_HistoryFaultTable */
extern Customer_fault_T *Get_SWC_Appl_History_Fault_Table(void);

/*====================================================================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *======================================================================================================================
 *
 * Date(dd-mm-yyyy)        userid                (Description on following lines: SCR #, etc.)
 *
 * 14-04-2021              gjy4d3(Vijayendra)              Initial version
 * 25-05-2021              gjy4d3(Vijayendra)              EEG-367: Implementation ticket for RNA SRR6 DV faults
 * 31-05-2021              gjy4d3(Vijayendra)              EEG-384: Implementation ticket for Nissan SRR6 DV faults (Mcu Temp Low
 fault)
 * 28-09-2021              gjy4d3(Vijayendra)              EEG-590: Clearing of the debouncing filters on the request of the
 customer domain[SRR6/FLR4/FLR4+]
 * 05-10-2021              gjy4d3(Vijayendra)              Updated for SRR6P build errors
 * 29-03-2022              djjx8v(Sristi)                  EEG-891: Bring FLR4p IPC fault implementation to Platform building block
 \*===================================================================================================================*/
#endif /* End FAULT_LIB_PRJ_H */
