#ifndef THERMAL_MONITOR_H
#define THERMAL_MONITOR_H
/*===========================================================================*\
 * FILE: thermal_monitor.h
 *===========================================================================
 * Copyright (C) 2021 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 *
 * DESCRIPTION:
 *   This file contains the header files for the Thermal Monitoring feature.
 *
 * ABBREVIATIONS:
 *   TMU - Thermal Monitoring Unit
 *
 * TRACEABILITY INFO:
 *   Design Document(s):
 *     TODO: Update list of design document(s)
 *
 *   Requirements Document(s):
 *     TODO: Update list of requirements document(s)
 *
 *   Applicable Standards (in order of precedence: highest first):
 *     ESGW_4-2_PE-SWX_00-01-A02_EN - "Aptiv C Coding Standards"
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
#include "Rte_SWC_PLT_Appl_IoHwAb_Type.h"
/*===========================================================================*\
 * Exported Preprocessor #define Constants
\*===========================================================================*/

#ifndef UNIT_TEST
   /* PVT0 */
   #define PVT0_CTRL1_ADDR    (*(volatile uint32_t *)0x890000B4)
   #define PVT0_CTRL0_ADDR    (*(volatile uint32_t *)0x890000B0)
   #define PVT0_CTRL3_ADDR    (*(volatile uint32_t *)0x890000BC)
   #define PVT0_CTRL4_ADDR    (*(volatile uint32_t *)0x890000C0)
   #define PVT0_IRQ_CTRL_ADDR (*(volatile uint32_t *)0x890000DC)
   #define PVT0_STAT0_ADDR    (*(volatile uint32_t *)0x890000D0)
   #define PVT0_STAT1_ADDR    (*(volatile uint32_t *)0x890000D4)
   #define OTP_PVT_TRIM_ADDR  (*(volatile uint32_t *)0x8B000EE4)
#endif
#define PVT0_PSAMPLE_Pos (4U)
#define PVT0_VSAMPLE_Pos (3U)
#define PVT0_TRIMG_Pos   (12U)
#define PVT0_TRIMO_Pos   (6U)

#define PVT0_PSAMPLE_Msk   (3UL << PVT0_PSAMPLE_Pos)
#define PVT0_VSAMPLE_Msk   (1UL << PVT0_VSAMPLE_Pos)
#define PVT0_TRIMG_Msk     (0x1FUL << PVT0_TRIMG_Pos)
#define PVT0_TRIMO_Msk     (0x3FUL << PVT0_TRIMO_Pos)
#define CTRL_PVT0_TRIMG(x) ((x) << PVT0_TRIMG_Pos)
#define CTRL_PVT0_TRIMO(x) ((x) << PVT0_TRIMO_Pos)

#define CTRL_PVT0_CK_EN 0x1
#define CTRL_PVT0_RUN   0x2

#define CTRL_PVT0_ALARM0_ACC 0x01000000
#define CTRL_PVT0_ALARM1_ACC 0x02000000
#define CTRL_PVT0_ACC_LEN    0x40

#define CTRL_PVT0_ALARM1_THR 0x39E
#define CTRL_PVT0_ALARM0_THR 0x39E

#define CTRL_PVT0_ALARM_ENA 0x30
#define CTRL_PVT0_SIG_ENA   0x8

#define STS_PVT0_DOUT_INS_MASK 0x3FF

#define STS_PVT0_DOUT_ACC_MASK 0xFFFF

#define CTL_PVT0_ALARM1_THR_OFFSET (16U)
#define CTL_PVT0_ACC_LEN_OFFSET    (16U)

/* PVT1 */
#define PVT1_CTRL1_ADDR  (*(volatile uint32_t *)0x890000E8)
#define PVT1_PSAMPLE_Pos (4U)
#define PVT1_VSAMPLE_Pos (3U)
#define PVT1_TRIMG_Pos   (12U)
#define PVT1_TRIMO_Pos   (6U)

#define PVT1_PSAMPLE_Msk   (3UL << PVT1_PSAMPLE_Pos)
#define PVT1_VSAMPLE_Msk   (1UL << PVT1_VSAMPLE_Pos)
#define PVT1_TRIMG_Msk     (0x1FUL << PVT1_TRIMG_Pos)
#define PVT1_TRIMO_Msk     (0x3FUL << PVT1_TRIMO_Pos)
#define CTRL_PVT1_TRIMG(x) ((x) << PVT1_TRIMG_Pos)
#define CTRL_PVT1_TRIMO(x) ((x) << PVT1_TRIMO_Pos)

#define PVT1_CTRL0_ADDR (*(volatile uint32_t *)0x890000E4)
#define CTRL_PVT1_CK_EN 0x1
#define CTRL_PVT1_RUN   0x2

#define PVT1_CTRL3_ADDR      (*(volatile uint32_t *)0x890000F0)
#define CTRL_PVT1_ALARM0_ACC 0x01000000
#define CTRL_PVT1_ALARM1_ACC 0x02000000
#define CTRL_PVT1_ACC_LEN    0x40

#define PVT1_CTRL4_ADDR      (*(volatile uint32_t *)0x890000F4)
#define CTRL_PVT1_ALARM1_THR 0x39E
#define CTRL_PVT1_ALARM0_THR 0x39E

#define PVT1_IRQ_CTRL_ADDR  (*(volatile uint32_t *)0x89000110)
#define CTRL_PVT1_ALARM_ENA 0x30
#define CTRL_PVT1_SIG_ENA   0x8

#define PVT1_STAT0_ADDR        (*(volatile uint32_t *)0x89000104)
#define STS_PVT1_DOUT_INS_MASK 0x3FF

#define PVT1_STAT1_ADDR        (*(volatile uint32_t *)0x89000108)
#define STS_PVT1_DOUT_ACC_MASK 0xFFFF

#define CTL_PVT1_ALARM1_THR_OFFSET (16U)
#define CTL_PVT1_ACC_LEN_OFFSET    (16U)

#define SYS_CTRL_PVT0_TRIMG_Pos     (0U)  /* Position of PVT0_TRIM Gain field */
#define SYS_CTRL_PVT0_TRIMO_Pos     (5U)  /* Position of PVT0_TRIM Offset field */
#define SYS_CTRL_PVT0_TRIM_FLAG_Pos (15U) /* Position of PVT0_TRIM Flag field */
#define SYS_CTRL_PVT1_TRIMG_Pos     (16U) /* Position of PVT1_TRIM Gain field */
#define SYS_CTRL_PVT1_TRIMO_Pos     (21U) /* Position of PVT1_TRIM Offset field */
#define SYS_CTRL_PVT1_TRIM_FLAG_Pos (31U) /* Position of PVT1_TRIM Flag field */

/* Macros for MASK value of TRIM Registers */
#define SYS_CTRL_PVT0_TRIMG_Msk     (0x1FUL << SYS_CTRL_PVT0_TRIMG_Pos)
#define SYS_CTRL_PVT0_TRIMO_Msk     (0x3FUL << SYS_CTRL_PVT0_TRIMO_Pos)
#define SYS_CTRL_PVT0_TRIM_FLAG_Msk (1UL << SYS_CTRL_PVT0_TRIM_FLAG_Pos)
#define SYS_CTRL_PVT1_TRIMG_Msk     (0x1FUL << SYS_CTRL_PVT1_TRIMG_Pos)
#define SYS_CTRL_PVT1_TRIMO_Msk     (0x3FUL << SYS_CTRL_PVT1_TRIMO_Pos)
#define SYS_CTRL_PVT1_TRIM_FLAG_Msk (1UL << SYS_CTRL_PVT1_TRIM_FLAG_Pos)

/* Default value of Trim offset and Gain */
#define DEFAULT_TRIMG_VALUE 0x0F
#define DEFAULT_TRIMO_VALUE 0x00
/*===========================================================================*\
 * Exported Preprocessor #define MACROS
\*===========================================================================*/

/*===========================================================================*\
 * Exported Type Declarations
\*===========================================================================*/
typedef struct PVT_Temperatures_Tag
{
   uint32_t PVT0_Inst_Temp_Raw_Value;
   uint32_t PVT1_Inst_Temp_Raw_Value;
   uint32_t PVT0_Avg_Temp_raw_Value;
   uint32_t PVT1_Avg_Temp_raw_Value;
} PVT_Temperatures_T;

typedef struct PVT_Temp_Celsius_Tag
{
   float32 PVT0_Inst_Temp_Value_C;
   float32 PVT1_Inst_Temp_Value_C;
   float32 PVT0_Avg_Temp_Value_C;
   float32 PVT1_Avg_Temp_Value_C;
} PVT_Temp_Celsius_T;

typedef enum PVT_Measurement_Tag
{
   PVT0_INST = 0,
   PVT1_INST,
   PVT0_AVG,
   PVT1_AVG,
   PVT_MAX
} PVT_Measurement_T;

typedef enum PVT_Measurement_Sites_Tag
{
   PVT0 = 0,
   PVT1,
   MAX_PVT
} PVT_Measurement_Sites_T;
/*===========================================================================*\
 * Exported Object Declarations
\*===========================================================================*/

/*===========================================================================*\
 * Exported Function Prototypes
\*===========================================================================*/
extern void PVT_Monitoring_Init(void);
extern void Update_Thermal_Monitor_Values(DT_Thermal_mon_mes_results_T *therm_mon_results);
/*===========================================================================*\
 * Exported Inline Function Definitions and #define Function-Like Macros
\*===========================================================================*/

/*===========================================================================*\
 * File Revision History (top to bottom: first revision to last revision)
 *===========================================================================
 *
 *  Date      Name      (Description on following lines: SCR #, etc.)
 * --------   -----     ---------------------------------------------
 * 20/01/2026 Sathvika  Created File
\*===========================================================================*/

#endif /* THERMAL_MONITOR_H */
