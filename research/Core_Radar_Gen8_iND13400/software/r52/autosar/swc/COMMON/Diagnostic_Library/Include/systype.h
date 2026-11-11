#ifndef SYSTYPE_H
#define SYSTYPE_H
/*****************************************************************************
 * Copyright 2006 Delphi Technologies, Inc., All Rights Reserved
 *
 * CM Synergy Header
 * %full_name: kok_css2#189/incl/systype.h/1 %
 * %created_by: dz5wdd %
 * %date_modified: Thu Jul 21 15:33:50 2016 %
 *
 *  Name:  systype.h
 *
 * File Description:
 *    This file contains the generic types for general use.
 *
 * Call-Tree for functions in this module:
 *
 * Traces To:
 *
 * Deviations from software standards: None
 *
 * Additional information contained in procedure header blocks:
 *
 *    Header blocks have the grep key of *. for design related
 *    information. (not including update information.)
 *
 *    Function header blocks have a list of SCRs that affect that routine.
 *
 * Updates to areas outside the scope of procedures:
 *    Refer to module footer comment block.
 *****************************************************************************/
/* defines for bitwise shifts */
#define ONE_BIT_SHIFT    1
#define TWO_BIT_SHIFT    2
#define THREE_BIT_SHIFT  3
#define FOUR_BIT_SHIFT   4
#define FIVE_BIT_SHIFT   5
#define TWENTY_BIT_SHIFT 20
#define ONE_BYTE_SHIFT   8
#define TWO_BYTE_SHIFT   16
#define THREE_BYTE_SHIFT 24

#define BITS_PER_BYTE     8
#define BITS_PER_WORD     16
#define BITS_PER_LONGWORD 32

#define NO_DATA 0

#define CLEAR 0 // bii 022306
/* CR 23572: Creates conflict with mpc5775k.h*/
/*#define SET   1  bii 022306*/

/* Following used to force Calibration values from EEprom to RAM */
#define CALCONST const

#ifndef NULL
   #define NULL (void *)0
#endif

/* added BYTE_x */
#define BYTE_0  0
#define BYTE_1  1
#define BYTE_2  2
#define BYTE_3  3
#define BYTE_4  4
#define BYTE_5  5
#define BYTE_6  6
#define BYTE_7  7
#define BYTE_8  (8)
#define BYTE_9  (9)
#define BYTE_10 (10)
#define BYTE_11 (11)
#define BYTE_12 (12)
#define BYTE_13 (13)
#define BYTE_14 (14)
#define BYTE_15 (15)
#define BYTE_16 (16)
#define BYTE_17 (17)
#define BYTE_18 (18)
#define BYTE_19 (19)
#define BYTE_20 (20)
#define BYTE_21 (21)
#define BYTE_22 (22)
#define BYTE_23 (23)
#define BYTE_24 (24)
#define BYTE_25 (25)

/*********************************
 * Exported #defines
 **********************************/

#define OUT0_M  0x00
#define OUT1_M  0x00
#define OUT2_M  0x00
#define OUT3_M  0x00
#define OUT4_M  0x00
#define OUT5_M  0x00
#define OUT6_M  0x00
#define OUT7_M  0x00
#define OUT8_M  0x00
#define OUT9_M  0x00
#define OUT10_M 0x00
#define OUT11_M 0x00
#define OUT12_M 0x00
#define OUT13_M 0x00
#define OUT14_M 0x00
#define OUT15_M 0x00

#define IN0_M  0x01
#define IN1_M  0x02
#define IN2_M  0x04
#define IN3_M  0x08
#define IN4_M  0x10
#define IN5_M  0x20
#define IN6_M  0x40
#define IN7_M  0x80
#define IN8_M  0x0100
#define IN9_M  0x0200
#define IN10_M 0x0400
#define IN11_M 0x0800
#define IN12_M 0x1000
#define IN13_M 0x2000
#define IN14_M 0x4000
#define IN15_M 0x8000

/* NEC specific Interrupt control registers handling */

#ifndef CLEAR_INT_REQ_FLAG
   #define CLEAR_INT_REQ_FLAG(INT_CTRL_REG) (INT_CTRL_REG .7 = 0)
#endif /* CLEAR_INT_REQ_FLAG */

#ifndef UNMASK_INT
   // #define UNMASK_INT(INT_CTRL_REG)         (INT_CTRL_REG.6 = 0)
   #define UNMASK_INT(INT_CTRL_REG) (INT_CTRL_REG &= 0b10111111)
#endif /* UNMASK_INT */

// #ifndef MASK_INT
// #define MASK_INT(INT_CTRL_REG)           (INT_CTRL_REG.6 = 1)
#define MASK_INT(INT_CTRL_REG1) (INT_CTRL_REG1 |= 0b01000000)
// #endif /* MASK_INT */

/*****************************
 * Pre-defined Standard Types
 ******************************/

#ifndef UNIT_TEST

typedef unsigned char unsigned8_T;
typedef unsigned short unsigned16_T;
// typedef unsigned long  unsigned32_T;

typedef unsigned short u6p10_T; // new
typedef signed char signed8_T;
typedef signed short signed16_T;
// typedef signed long  signed32_T;
typedef signed16_T s5p10_T; // new

typedef unsigned char bit_field_T; /* To be used for all bit fields. */

/* Pointer to function type */
typedef void (*ptr_to_function_T)(void);

#endif /*UNIT_TEST*/
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 * boolean_T
 *
 * Rules for using boolean_T (to be checked at code reviews):
 *
 * 1) boolean_T declared variables shall be named such that a state is
 *    conveyed. Examples: lamp_is_on,  test_passed,  pin_is_high.  So
 *    that if( lamp_is_on ) is unambiguous.
 *
 * 2) boolean_T variables shall only be compared by themselves.
 *    Never do this:  if( TRUE==lamp_is_on)  Do this: if( lamp_is_on )
 *
 * 3) boolean_T variables shall not be compared to each other.
 *    Never do this:  if ( lamp_is_on == time_for_light )
 *
 * 4) boolean_T variables can be assigned TRUE or FALSE
 *    Can do this:  lamp_is_on = TRUE;
 *
 *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#ifndef UNIT_TEST
typedef unsigned8_T boolean_T;
#endif /*UINIT_TEST*/
#ifndef FALSE
   #define FALSE 0
#endif

#ifndef TRUE
   #define TRUE 1
#endif

#ifndef OFF
   #define OFF FALSE
#endif

#ifndef ON
   #define ON TRUE
#endif

/******************************
 * Defines for Portability
 *******************************/
/*#define PAGEZERO  @dir
  #define INTERRUPT @interrupt
  #define FAR       @far
  #define EEPROM    @eeprom
  #define TASK      @far void
*/

#define PAGEZERO
//#define INTERRUPT// RS: FIXIT
#define FAR
#define EEPROM
//#define TASK

/* Pointer to FAR function type */
typedef void (*ptr_to_far_function_T)(void);

/* System State type definitions */
typedef enum
{
   ENABLED_OFF        = 0,
   DISABLED           = 1,
   ENABLED_ON         = 2,
   DIAGNOSTIC_STATE_1 = 3,
   SELF_TEST          = 4
} system_state_T;

/* Diagnostic Session type definition */
typedef enum
{
   DEFAULT_SESSION_0x81 = 0,
   PROG_SESSION_0x85    = 1
} diagnostic_session_T;
#if 0
typedef enum
{
   UNDER_V,
   LO_V,
   NORM_V,
   HI_V,
   OVER_V
} v_ign_state_T;

typedef enum
{
   V_RANGE_CAN,
   V_RANGE_DTC,
   V_RANGE_DBUA_RADAR_ON,
   V_RANGE_DBUA_RADAR_OFF,
   V_RANGE_PLACEHOLDER_3,
   NUM_V_RANGE_CONTROLLED_FEATURES
} v_range_features_T;
#endif
/* Priority Level type definition is a range from 1 to 20 */
typedef unsigned8_T priority_level_T;

/* 8 bit value type that has a range from 0 to <1 with a
 * precision of 1/256.
 */
typedef unsigned8_T percent_T;

/* 8 bit time type that has a range from 0 to <128 with a
 * precision of 0.5.
 */
typedef unsigned8_T seconds_7p1_T;

/* 8 bit speed type that has a range from 0 to <128 with a
 * precision of 0.5.
 */
typedef unsigned8_T MPH_u7p1_T;

/* REMOVE this after all references to it are gone */
typedef unsigned8_T MPH_7p1_T;

/* Added for time and speed calcuations */
typedef unsigned16_T TIME_u12p4_T;
typedef unsigned16_T SPEED_u12p4_T;
typedef unsigned16_T FLT_CONST_u0p16_T;

typedef unsigned8_T IQ_BALANCER_u3p5_T;
#if 0
typedef struct
{
   bit_field_T Enable      :1;
   bit_field_T Current   :1;
   bit_field_T Unused_Bit2  :1;
   bit_field_T Unused_Bit3  :1;
   bit_field_T History      :1;
   bit_field_T Self_Test    :1;
   bit_field_T Unused_Bit6   :1;
   bit_field_T Unused_Bit7    :1;
} DTC_status_T;
#endif
typedef struct
{
   unsigned8_T Dim;
   unsigned8_T Ignition;
   unsigned8_T Eight_Volt;

} Analog_Input_Counts_T;

typedef union
{
   unsigned8_T DTC_fault_byte;
   bit_field_T DTCFaultSymptom:4;
   bit_field_T DTCReadinessFlag:1;
   bit_field_T DTCStorageState:2;
   bit_field_T DTCWarningLampCalibrationStatus:1;

} DTC_fault_status_T;

typedef enum
{
   ASCII_DASH = 0x2D,
   ASCII_0    = 0x30,
   ASCII_1    = 0x31,
   ASCII_2    = 0x32,
   ASCII_3    = 0x33,
   ASCII_4    = 0x34,
   ASCII_5    = 0x35,
   ASCII_6    = 0x36,
   ASCII_7    = 0x37,
   ASCII_8    = 0x38,
   ASCII_9    = 0x39,
   ASCII_A    = 0x41,
   ASCII_B    = 0x42,
   ASCII_C    = 0x43,
   ASCII_D    = 0x44,
   ASCII_E    = 0x45,
   ASCII_F    = 0x46,
   ASCII_G    = 0x47,
   ASCII_H    = 0x48,
   ASCII_I    = 0x49,
   ASCII_J    = 0x4A,
   ASCII_K    = 0x4B,
   ASCII_L    = 0x4C,
   ASCII_M    = 0x4D,
   ASCII_N    = 0x4E,
   ASCII_O    = 0x4F,
   ASCII_P    = 0x50,
   ASCII_Q    = 0x51,
   ASCII_R    = 0x52,
   ASCII_S    = 0x53,
   ASCII_T    = 0x54,
   ASCII_U    = 0x55,
   ASCII_V    = 0x56,
   ASCII_W    = 0x57,
   ASCII_X    = 0x58,
   ASCII_Y    = 0x59,
   ASCII_Z    = 0x5A

} ASCII_alphanumeric_T;

typedef enum
{
   BYTE_2_SUFFIX_A = 0x00,
   BYTE_2_SUFFIX_B = 0x01,
   BYTE_2_SUFFIX_C = 0x02,
   BYTE_2_SUFFIX_D = 0x03,
   BYTE_2_SUFFIX_E = 0x04,
   BYTE_2_SUFFIX_F = 0x05,
   BYTE_2_SUFFIX_G = 0x06,
   BYTE_2_SUFFIX_H = 0x07,
   BYTE_2_SUFFIX_J = 0x08,
   BYTE_2_SUFFIX_K = 0x09,
   BYTE_2_SUFFIX_L = 0x0A,
   BYTE_2_SUFFIX_M = 0x0B,
   BYTE_2_SUFFIX_N = 0x0C,
   BYTE_2_SUFFIX_P = 0x0D,
   BYTE_2_SUFFIX_R = 0x0E,
   BYTE_2_SUFFIX_S = 0x0F,
   BYTE_2_SUFFIX_T = 0x10,
   BYTE_2_SUFFIX_U = 0x11,
   BYTE_2_SUFFIX_V = 0x12,
   BYTE_2_SUFFIX_W = 0x13,
   BYTE_2_SUFFIX_X = 0x14,
   BYTE_2_SUFFIX_Y = 0x15,
   BYTE_2_SUFFIX_Z = 0x16

} Part_ID_Suffix_2_T;

typedef enum
{
   BYTE_1_SUFFIX_A = (0x00 << 1),
   BYTE_1_SUFFIX_B = (0x01 << 1),
   BYTE_1_SUFFIX_C = (0x02 << 1),
   BYTE_1_SUFFIX_D = (0x03 << 1),
   BYTE_1_SUFFIX_E = (0x04 << 1),
   BYTE_1_SUFFIX_F = (0x05 << 1),
   BYTE_1_SUFFIX_G = (0x06 << 1),
   BYTE_1_SUFFIX_H = (0x07 << 1),
   BYTE_1_SUFFIX_J = (0x08 << 1),
   BYTE_1_SUFFIX_K = (0x09 << 1),
   BYTE_1_SUFFIX_L = (0x0A << 1),
   BYTE_1_SUFFIX_M = (0x0B << 1),
   BYTE_1_SUFFIX_N = (0x0C << 1),
   BYTE_1_SUFFIX_P = (0x0D << 1),
   BYTE_1_SUFFIX_R = (0x0E << 1),
   BYTE_1_SUFFIX_S = (0x0F << 1),
   BYTE_1_SUFFIX_T = (0x10 << 1),
   BYTE_1_SUFFIX_U = (0x11 << 1),
   BYTE_1_SUFFIX_V = (0x12 << 1),
   BYTE_1_SUFFIX_W = (0x13 << 1),
   BYTE_1_SUFFIX_X = (0x14 << 1),
   BYTE_1_SUFFIX_Y = (0x15 << 1),
   BYTE_1_SUFFIX_Z = (0x16 << 1)

} Part_ID_Suffix_1_T;

/******************************
 * Constant Values
 *******************************/
/* Size of an Address in Bytes */
#define C_AddressSize 2

/***************************************************************************
 * Revision History
 *
 * Date     By   Description
 * -------- --- -----------
 * 01/24/07 rs  SCR#6882 for release 10018753_esr_gm_host/1.0
 *              Initial baseline from the Aplication Software of the same
 *              Project.
 * 06/19/07 rs  SCR#6882 for release 10018753_esr_gm_host/1.0
 *              Added #define macros for OUTX_M and INX_M
 * 05-Dec-2014	tznwzd	CR 23572 Modifications made to incoporate new Race Runner Header Ver 2.3
 * 						(Replacing ver 1.1.)
 ****************************************************************************/
#endif /* SYSTYPE_H */
